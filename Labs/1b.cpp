#include <iostream>
#include <string>
using namespace std;

bool is_valid_signed_integer(const string &number) {
    enum State { q0, q1, q2, dead };
    State state = q0;

    for (char ch : number) {
        switch (state) {
            case q0:
                if (ch == '+' || ch == '-') {
                    state = q1;
                } else if (isdigit(ch)) {
                    state = q2;
                } else {
                    state = dead;
                }
                break;
            case q1:
                if (isdigit(ch)) {
                    state = q2;
                } else {
                    state = dead;
                }
                break;
            case q2:
                if (isdigit(ch)) {
                    state = q2;
                } else {
                    state = dead;
                }
                break;
            default:
                state = dead;
                break;
        }

        if (state == dead) break;
    }

    return state == q2;
}

int main() {
    // Test cases
    string test_cases[] = {"+123", "-456", "789", "12a", "+-12"};
    for (const string &test_case : test_cases) {
        if (is_valid_signed_integer(test_case)) {
            cout << test_case << " is Accepted" << endl;
        } else {
            cout << test_case << " is Rejected" << endl;
        }
    }
    return 0;
}