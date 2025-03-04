#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTIONS 10
#define MAX_SYMBOLS 10
#define MAX_ITEMS 20
#define MAX_STATES 20

typedef struct
{
    int production_no;
    int dot_position;
} LR0Item;

typedef struct
{
    LR0Item items[MAX_ITEMS];
    int item_count;
} State;

typedef struct
{
    char lhs;
    char rhs[MAX_SYMBOLS];
} Production;

Production productions[MAX_PRODUCTIONS];
int production_count = 0;

void add_production(char lhs, const char *rhs)
{
    productions[production_count].lhs = lhs;
    strcpy(productions[production_count].rhs, rhs);
    production_count++;
}

// Function to check for left recursion
int has_left_recursion()
{
    for (int i = 0; i < production_count; i++)
    {
        if (productions[i].lhs == productions[i].rhs[0])
        {
            return 1;  // Left recursion detected
        }
    }
    return 0;
}

void print_item(LR0Item item)
{
    printf("%c -> ", productions[item.production_no].lhs);
    for (int i = 0; productions[item.production_no].rhs[i] != '\0'; i++)
    {
        if (i == item.dot_position)
        {
            printf("·");
        }
        printf("%c", productions[item.production_no].rhs[i]);
    }
    if (item.dot_position == strlen(productions[item.production_no].rhs))
    {
        printf("·");
    }
    printf("\n");
}

void closure(State *state)
{
    int changed;
    do
    {
        changed = 0;
        for (int i = 0; i < state->item_count; i++)
        {
            LR0Item item = state->items[i];
            char symbol = productions[item.production_no].rhs[item.dot_position];
            if (symbol >= 'A' && symbol <= 'Z')
            {
                for (int j = 0; j < production_count; j++)
                {
                    if (productions[j].lhs == symbol)
                    {
                        LR0Item new_item = {j, 0};
                        int found = 0;
                        for (int k = 0; k < state->item_count; k++)
                        {
                            if (state->items[k].production_no == new_item.production_no &&
                                state->items[k].dot_position == new_item.dot_position)
                            {
                                found = 1;
                                break;
                            }
                        }
                        if (!found)
                        {
                            state->items[state->item_count++] = new_item;
                            changed = 1;
                        }
                    }
                }
            }
        }
    } while (changed);
}

State goto_state(State state, char symbol)
{
    State new_state;
    new_state.item_count = 0;

    for (int i = 0; i < state.item_count; i++)
    {
        LR0Item item = state.items[i];
        if (productions[item.production_no].rhs[item.dot_position] == symbol)
        {
            LR0Item new_item = {item.production_no, item.dot_position + 1};
            new_state.items[new_state.item_count++] = new_item;
        }
    }

    closure(&new_state);
    return new_state;
}

int states_are_equal(State *s1, State *s2)
{
    if (s1->item_count != s2->item_count)
        return 0;
    for (int i = 0; i < s1->item_count; i++)
    {
        if (s1->items[i].production_no != s2->items[i].production_no ||
            s1->items[i].dot_position != s1->items[i].dot_position)
        {
            return 0;
        }
    }
    return 1;
}

int check_conflicts(State state)
{
    int has_shift = 0;
    int has_reduce = 0;

    for (int i = 0; i < state.item_count; i++)
    {
        LR0Item item = state.items[i];
        if (productions[item.production_no].rhs[item.dot_position] == '\0')
        {
            has_reduce = 1;
        }
        else
        {
            has_shift = 1;
        }

        if (has_shift && has_reduce)
        {
            return 1;
        }
    }

    if (has_reduce)
    {
        int reduction_count = 0;
        for (int i = 0; i < state.item_count; i++)
        {
            LR0Item item = state.items[i];
            if (productions[item.production_no].rhs[item.dot_position] == '\0')
            {
                reduction_count++;
                if (reduction_count > 1)
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int is_LR0(State *states, int state_count)
{
    for (int i = 0; i < state_count; i++)
    {
        if (check_conflicts(states[i]))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    printf("No. of productions: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char a;
        char b[10];
        scanf(" %c", &a);
        scanf("%s", b);
        add_production(a, b);
    }

    if (has_left_recursion())
    {
        printf("The grammar has left recursion and is not LR(0).\n");
        return 1;  
    }

    State initial_state;
    initial_state.item_count = 0;

    for (int i = 0; i < production_count; i++)
    {
        if (productions[i].lhs == 'E')
        {
            initial_state.items[initial_state.item_count++] = (LR0Item){i, 0};
        }
    }
    closure(&initial_state);

    State states[MAX_STATES];
    int state_count = 0;
    states[state_count++] = initial_state;

    char all_symbols[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < state_count; i++)
    {
        for (int j = 0; j < strlen(all_symbols); j++)
        {
            char symbol = all_symbols[j];
            State new_state = goto_state(states[i], symbol);
            if (new_state.item_count > 0)
            {
                int exists = 0;
                for (int k = 0; k < state_count; k++)
                {
                    if (states_are_equal(&states[k], &new_state))
                    {
                        exists = 1;
                        break;
                    }
                }
                if (!exists)
                {
                    if (state_count >= MAX_STATES)
                    {
                        printf("Error: State limit exceeded\n");
                        return 1;
                    }
                    states[state_count++] = new_state;
                }
            }
        }
    }

    if (is_LR0(states, state_count))
    {
        printf("The grammar is not LR(0).\n");
    }
    else
    {
        printf("The grammar is LR(0).\n");
    }

    return 0;
}