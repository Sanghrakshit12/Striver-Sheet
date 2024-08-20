#include <bits/stdc++.h>
using namespace std;

string ConvertDecimaltoBinary(int n){
    string str = "";
    while (n != 0)
    {
        if (n % 2)
            str += '1';
        else
            str += '0';
        n = n / 2;
    }
    reverse(str.begin(), str.end());
    return str;
}

int ConvertBinarytoDecimal(string s){
    int n = s.length();
    int c = 0, res = 0;
    while (c < n){
        if (s[n - c - 1]=='1')
            res += pow(2, c) * 1;
        c++;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    string s = ConvertDecimaltoBinary(n);
    cout << s << endl;
    int res = ConvertBinarytoDecimal(s);
    cout << res;
}