#include <iostream>
#include <string>
using namespace std;

bool is_valid_c_identifier(const string &identifier) {
    enum State { q0, q1, dead };
    State state = q0;

    for (char ch : identifier) {
        switch (state) {
            case q0:
                if (isalpha(ch) || ch == '_') {
                    state = q1;
                } else {
                    state = dead;
                }
                break;
            case q1:
                if (isalnum(ch) || ch == '_') {
                    state = q1;
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

    return state == q1;
}

int main() {
    // Test cases
    string test_cases[] = {"myVar123", "_tempVar", "3var", "var-name"};
    for (const string &test_case : test_cases) {
        if (is_valid_c_identifier(test_case)) {
            cout << test_case << " is Accepted" << endl;
        } else {
            cout << test_case << " is Rejected" << endl;
        }
    }
    return 0;
}