#include <bits/stdc++.h>
using namespace std;

// Reversing characters of each word in string
// string Brute(string str){
//     if (str == "")
//         return str;
//     str += ' ';
//     string res = "";
//     string s = "";
//     int n = str.length();
//     for (int i = 0; i < n; i++){
//         if (str[i] != ' ')
//             s += str[i];
//         else{
//             int m = s.length();
//             int l = 0, h = m - 1;
//             while (l < h)
//                 swap(s[l++], s[h--]);
//             res += s;
//             res += ' ';
//             s = "";
//         }
//     }
//     if (!res.empty() && res[res.length() - 1] == ' ')
//         res.pop_back();
//     return res;
// }

//
// string Brute1(string str){
//     str = str + ' ';
//     int n = str.length();
//     string st="",res="";
//     stack<string> stk;
//     for (int i = 0; i < n; i++){
//         if (str[i] != ' ')
//             st += str[i];
//         else{
//             stk.push(st);
//             st = "";
//         }
//     }
//     while(!stk.size()==1){
//         res+=stk.top()+' ';
//         stk.pop();
//     }
//     res+=stk.top();
//     stk.pop();
//     return res;
// }

// No leading or trailing zeros

// string Optimal(string str){
// str+=' ';
// int n=str.length();
// string res="",st="";
// for(int i=0;i<n;i++){
//     if(str[i]!=' '){
//         st+=str[i];
//     }
//     else{
//         res=st+' '+res;
//         st="";
//     }
// }
// return res;
// }

string reverseWords(string str){
    int i = 0, r = 0, l = 0;
    int n = str.length();
    reverse(str.begin(), str.end());
    while (i < n){
        while (i < n && str[i] == ' ')
            i++;

        if (i == n)
            break;

        if (r != 0)
            str[r++] = ' ';

        l = r;
        while (i < n && str[i] != ' ')
            str[r++] = str[i++];

        reverse(str.begin() + l, str.begin() + r);
    }

    str.resize(r);
    return str;
}

int main(){
    string str;
    getline(cin, str);
    string res = reverseWords(str);
    cout << res;
}