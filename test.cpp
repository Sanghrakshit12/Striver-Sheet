#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
struct Rule {
    char lhs;                 
    string rhs;              
};

vector<Rule> grammar = {
    {'S', "L=R"},
    {'S', "R"},
    {'L', "*R"},
    {'L', "id"},
    {'R', "L"}
};

map<char, set<char>> firstSet, followSet;
set<char> terminals = {'=', '*', 'i', 'd'}; 
set<char> nonTerminals = {'S', 'L', 'R'};

void computeFirst() {
    bool changed = true;

    while (changed) {
        changed = false;

        for (auto &rule : grammar) {
            char lhs = rule.lhs;
            string rhs = rule.rhs;

            for (char symbol : rhs) {
                if (terminals.count(symbol)) {
                    if (firstSet[lhs].insert(symbol).second) {
                        changed = true;
                    }
                    break;
                } else if (nonTerminals.count(symbol)) {
                    size_t sizeBefore = firstSet[lhs].size();
                    firstSet[lhs].insert(firstSet[symbol].begin(), firstSet[symbol].end());
                    if (firstSet[lhs].size() > sizeBefore) {
                        changed = true;
                    }
                    break;
                }
            }
        }
    }
}
//If it’s a terminal, add it to FIRST(lhs) and stop.
// If it’s a non-terminal, add its FIRST set to FIRST(lhs)
void computeFollow() {
    followSet['S'].insert('$'); 
    bool changed = true;

    while (changed) {
        changed = false;

        for (auto &rule : grammar) {
            char lhs = rule.lhs;
            string rhs = rule.rhs;

            for (size_t i = 0; i < rhs.size(); ++i) {
                char symbol = rhs[i];
                if (nonTerminals.count(symbol)) {
                    size_t sizeBefore = followSet[symbol].size();
                    if (i == rhs.size() - 1) {
                        followSet[symbol].insert(followSet[lhs].begin(), followSet[lhs].end());
                    } else {
                        char nextSymbol = rhs[i + 1];
                        if (terminals.count(nextSymbol)) {
                            followSet[symbol].insert(nextSymbol);
                        } else if (nonTerminals.count(nextSymbol)) {
                            followSet[symbol].insert(firstSet[nextSymbol].begin(), firstSet[nextSymbol].end());
                        }
                    }

                    if (followSet[symbol].size() > sizeBefore) {
                        changed = true;
                    }
                }
            }
        }
    }
}

//or each rule:
// Traverse each symbol in rhs.
// If it’s a non-terminal:
// Add FOLLOW of lhs to it if it’s the last symbol.
// Otherwise, add the FIRST of the next symbol.
void printSet(const map<char, set<char>> &sets, const string &name) {
    cout << name << " sets:\n";
    for (auto &entry : sets) {
        cout << entry.first << ": { ";
        for (char c : entry.second) cout << c << " ";
        cout << "}\n";
    }
}

int main() {
    computeFirst();
    computeFollow();
    printSet(firstSet, "FIRST");
    printSet(followSet, "FOLLOW");

    cout << "Analyzing for SLR(1):\n";
    bool isSLR = true;

    for (auto &rule : grammar) {
        char lhs = rule.lhs;
        string rhs = rule.rhs;
        set<char> intersection;
        set_intersection(
            followSet[lhs].begin(), followSet[lhs].end(),
            firstSet[lhs].begin(), firstSet[lhs].end(),
            inserter(intersection, intersection.begin())
        );

        if (!intersection.empty()) {
            cout << "Conflict detected for rule " << lhs << " -> " << rhs << "\n";
            isSLR = false;
        }
    }

    if (isSLR) {
        cout << "The grammar is SLR(1).\n";
    } else {
        cout << "The grammar is NOT SLR(1).\n";
    }

    return 0;
}