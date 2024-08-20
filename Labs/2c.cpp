#include <iostream>
#include <string>
#include <cctype>

// DFA states
enum State {
    START,
    SIGN,
    INTEGER_PART,
    DECIMAL_POINT,
    FRACTIONAL_PART,
    EXPONENT_SIGN,
    EXPONENT_PART,
    ACCEPT,
    REJECT
};

// Function to get the next state
State transition(State currentState, char input) {
    switch (currentState) {
        case START:
            if (input == '+' || input == '-') return SIGN;
            if (isdigit(input)) return INTEGER_PART;
            return REJECT;

        case SIGN:
            if (isdigit(input)) return INTEGER_PART;
            return REJECT;

        case INTEGER_PART:
            if (isdigit(input)) return INTEGER_PART;
            if (input == '.') return DECIMAL_POINT;
            if (input == 'e' || input == 'E') return EXPONENT_SIGN;
            return REJECT;

        case DECIMAL_POINT:
            if (isdigit(input)) return FRACTIONAL_PART;
            return REJECT;

        case FRACTIONAL_PART:
            if (isdigit(input)) return FRACTIONAL_PART;
            if (input == 'e' || input == 'E') return EXPONENT_SIGN;
            return ACCEPT;

        case EXPONENT_SIGN:
            if (input == '+' || input == '-') return EXPONENT_PART;
            if (isdigit(input)) return EXPONENT_PART;
            return REJECT;

        case EXPONENT_PART:
            if (isdigit(input)) return EXPONENT_PART;
            return ACCEPT;

        default:
            return REJECT;
    }
}

bool isConstant(const std::string &input) {
    State currentState = START;

    for (char ch : input) {
        currentState = transition(currentState, ch);
        if (currentState == REJECT) return false;
    }

    return currentState == INTEGER_PART || currentState == FRACTIONAL_PART || currentState == EXPONENT_PART || currentState == ACCEPT;
}

int main() {
    std::string input;
    std::cout << "Enter a constant: ";
    std::cin >> input;

    if (isConstant(input)) {
        std::cout << "The input is a valid constant." << std::endl;
    } else {
        std::cout << "The input is not a valid constant." << std::endl;
    }

    return 0;
}
