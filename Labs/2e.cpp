#include <iostream>
#include <string>

using namespace std;

enum State {q0, q1, q2, q3, q4};

bool recognizePattern(const string &str) {
    State currentState = q0;

    for (char ch : str) {
        switch (currentState) {
            case q0:
                if (ch == 'a') {
                    currentState = q1;
                } else if (ch == 'b') {
                    currentState = q2;
                } else {
                    return false;
                }
                break;

            case q1:
                if (ch == 'a') {
                    currentState = q3;
                } else if (ch == 'b') {
                    currentState = q2;
                } else {
                    return false;
                }
                break;

            case q2:
                if (ch == 'b') {
                    currentState = q2;
                } else {
                    return false;
                }
                break;

            case q3:
                if (ch == 'a') {
                    currentState = q3;
                } else if (ch == 'b') {
                    currentState = q2;
                } else {
                    return false;
                }
                break;
            case q4:
                if (ch == 'a' || ch=='b') {
                    return false;
                }
                break;
            default:
                return false;
        }
    }

    return currentState == q1 || currentState == q2;
}

int main() {
    string input;
    cout << "Enter a string to check if it matches 'a', 'a*b+', or 'abb': ";
    cin >> input;

    if (recognizePattern(input)) {
        cout << "\"" << input << "\" is a valid string for one of the patterns." << endl;
    } else {
        cout << "\"" << input << "\" is not a valid string for any of the patterns." << endl;
    }

    return 0;
}