#include <bits/stdc++.h>
using namespace std;

bool palin(string str, int i, int n){
    if (i >= n / 2)
        return 1;
    if (str[i] != str[n - i - 1])
        return 0;
    return palin(str, i + 1, n);
}

int main(){
    string str;
    getline(cin, str);
    int n = str.length();
    cout << palin(str, 0, n);
}