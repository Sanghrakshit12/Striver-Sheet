#include <iostream>
#include <string>

using namespace std;

// DFA states
enum State {
    START,
    SIGN,
    INTEGER_PART,
    DECIMAL_POINT,
    FRACTIONAL_PART,
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
            return REJECT;
        case DECIMAL_POINT:
            if (isdigit(input)) return FRACTIONAL_PART;
            return REJECT;
        case FRACTIONAL_PART:
            if (isdigit(input)) return FRACTIONAL_PART;
            return REJECT;
        default:
            return REJECT;
    }
}

bool isSignedRealNumber(const string &input) {
    State currentState = START;
    
    for (char ch : input) {
        currentState = transition(currentState, ch);
        if (currentState == REJECT) return false;
    }

    return currentState == INTEGER_PART || currentState == FRACTIONAL_PART;
}

int main() {
    string input;
    cout << "Enter a signed real number: ";
    cin >> input;

    if (isSignedRealNumber(input)) {
        cout << "The input is a valid signed real number." << endl;
    } else {
        cout << "The input is not a valid signed real number." << endl;
    }

    return 0;
}
