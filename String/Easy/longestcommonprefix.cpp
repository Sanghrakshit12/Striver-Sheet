#include <bits/stdc++.h>
using namespace std;

// O(nlogn)+O(min(first,last))  O(n)
string Brute(vector<string> str){
    int n = str.size();
    if (n == 0)
        return "";
    if (n == 1)
        return str[0];
    sort(str.begin(), str.end());
    int n1 = str[0].length();
    int n2 = str[n - 1].length();
    int x = min(n1, n2);
    string first = str[0], last = str[n - 1];
    int i = 0;
    while (i < x && first[i] == last[i])
        i++;
    return first.substr(0, i);
}

// O(Sum of length of all String) O(1)
string longestCommonPrefix(vector<string> str){
    string res = "";
    int x = str[0].length();
    int n = str.size();
    for (int i = 0; i < x; i++){
        for (int j = 1; j < n; j++){
            if (str[0][i] != str[j][i])
                return str[0].substr(0, i);
        }
    }
    return str[0];
}

int main()
{
    vector<string> str = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(str);
}