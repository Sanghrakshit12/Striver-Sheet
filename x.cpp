#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1005

int solve(char s[MAXSIZE], char t[MAXSIZE], int k) {
    int n = strlen(s);
    if (n > k) return 0;  // If string length is greater than k, it's impossible

    vector<bool> used(n, false);
    
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (!used[j]) {
                char shifted = ((s[j] - 'a' + i) % 26) + 'a';
                if (shifted == t[j]) {
                    used[j] = true;
                    break;
                }
            }
        }
    }

    // Check if all characters were successfully shifted
    for (int i = 0; i < n; i++) {
        if (!used[i]) return 0;
    }

    return 1;
}

int main() {
    char s[MAXSIZE], t[MAXSIZE];
    int k;
    
    // Input strings s, t and integer k
    scanf("%s", s);
    scanf("%s", t);
    scanf("%d", &k);
    
    // Check if the strings can be transformed with at most k operations
    if (solve(s, t, k) == 0)
        printf("No\n");
    else
        printf("Yes\n");
    
    return 0;
}