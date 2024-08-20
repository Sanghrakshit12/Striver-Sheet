#include <iostream>
#include <string>
#include <unordered_map>

// DFA states
enum State {
    START,
    I, IF, 
    E, EL, ELS, ELSE,
    IN, INT, 
    F, FL, FLO, FLOT, FLOAT,
    V, VO, VOI, VOID,
    C, CH, CHA, CHAR,
    D, DO,
    W, WH, WHI, WHIL, WHILE,
    ACCEPT, REJECT
};

// Function to get the next state
State transition(State currentState, char input) {
    switch (currentState) {
        case START:
            if (input == 'i') return I;
            if (input == 'e') return E;
            if (input == 'f') return F;
            if (input == 'v') return V;
            if (input == 'c') return C;
            if (input == 'd') return D;
            if (input == 'w') return W;
            return REJECT;
        
        case I:
            if (input == 'f') return IF;
            if (input == 'n') return IN;
            return REJECT;
        
        case IF:
            return REJECT;
        
        case E:
            if (input == 'l') return EL;
            return REJECT;

        case EL:
            if (input == 's') return ELS;
            return REJECT;

        case ELS:
            if (input == 'e') return ELSE;
            return REJECT;

        case ELSE:
            return REJECT;

        case IN:
            if (input == 't') return INT;
            return REJECT;

        case INT:
            return REJECT;

        case F:
            if (input == 'l') return FL;
            return REJECT;

        case FL:
            if (input == 'o') return FLO;
            return REJECT;

        case FLO:
            if (input == 'a') return FLOT;
            return REJECT;

        case FLOT:
            if (input == 't') return FLOAT;
            return REJECT;

        case FLOAT:
            return REJECT;

        case V:
            if (input == 'o') return VO;
            return REJECT;

        case VO:
            if (input == 'i') return VOI;
            return REJECT;

        case VOI:
            if (input == 'd') return VOID;
            return REJECT;

        case VOID:
            return REJECT;

        case C:
            if (input == 'h') return CH;
            return REJECT;

        case CH:
            if (input == 'a') return CHA;
            return REJECT;

        case CHA:
            if (input == 'r') return CHAR;
            return REJECT;

        case CHAR:
            return REJECT;

        case D:
            if (input == 'o') return DO;
            return REJECT;

        case DO:
            return REJECT;

        case W:
            if (input == 'h') return WH;
            return REJECT;

        case WH:
            if (input == 'i') return WHI;
            return REJECT;

        case WHI:
            if (input == 'l') return WHIL;
            return REJECT;

        case WHIL:
            if (input == 'e') return WHILE;
            return REJECT;

        case WHILE:
            return REJECT;

        default:
            return REJECT;
    }
}

bool isKeyword(const std::string &input) {
    State currentState = START;
    
    for (char ch : input) {
        currentState = transition(currentState, ch);
        if (currentState == REJECT) return false;
    }

    return currentState == IF || currentState == ELSE || currentState == INT || 
           currentState == FLOAT || currentState == VOID || currentState == CHAR || 
           currentState == DO || currentState == WHILE;
}

int main() {
    std::string input;
    std::cout << "Enter a keyword: ";
    std::cin >> input;

    if (isKeyword(input)) {
        std::cout << "The input is a valid C keyword." << std::endl;
    } else {
        std::cout << "The input is not a valid C keyword." << std::endl;
    }

    return 0;
}
