#include <iostream>
#include <string>

// DFA states
enum State {
    START,
    PLUS, MINUS, MUL, DIV,
    ASSIGN, EQ, NOT, NEQ,
    LT, LE, GT, GE,
    AND1, AND2,
    OR1, OR2,
    ACCEPT, REJECT
};

// Function to get the next state for operators
State operatorTransition(State currentState, char input) {
    switch (currentState) {
        case START:
            if (input == '+') return PLUS;
            if (input == '-') return MINUS;
            if (input == '*') return MUL;
            if (input == '/') return DIV;
            if (input == '=') return ASSIGN;
            if (input == '!') return NOT;
            if (input == '<') return LT;
            if (input == '>') return GT;
            if (input == '&') return AND1;
            if (input == '|') return OR1;
            return REJECT;

        case ASSIGN:
            if (input == '=') return EQ;
            return REJECT;

        case NOT:
            if (input == '=') return NEQ;
            return REJECT;

        case LT:
            if (input == '=') return LE;
            return REJECT;

        case GT:
            if (input == '=') return GE;
            return REJECT;

        case AND1:
            if (input == '&') return AND2;
            return REJECT;

        case OR1:
            if (input == '|') return OR2;
            return REJECT;

        default:
            return REJECT;
    }
}

bool isOperator(const std::string &input) {
    State currentState = START;

    for (char ch : input) {
        currentState = operatorTransition(currentState, ch);
        if (currentState == REJECT) return false;
    }

    return currentState == PLUS || currentState == MINUS || currentState == MUL || currentState == DIV ||
           currentState == EQ || currentState == NEQ || currentState == LE || currentState == GE ||
           currentState == AND2 || currentState == OR2;
}

int main() {
    std::string input;
    std::cout << "Enter an operator: ";
    std::cin >> input;

    if (isOperator(input)) {
        std::cout << "The input is a valid operator." << std::endl;
    } else {
        std::cout << "The input is not a valid operator." << std::endl;
    }

    return 0;
}
