#include <bits/stdc++.h>
using namespace std;

bool isValid(string s){
    int n = s.length();
    stack<char> st;
    for (int i = 0; i < n; i++){
        if (s[i] == ')'){
            if (st.empty() || st.top() != '(')
                return 0;
            st.pop();
        }
        else if (s[i] == ']'){
            if (st.empty() || st.top() != '[')
                return 0;
            st.pop();
        }
        else if (s[i] == '}'){
            if (st.empty() || st.top() != '{')
                return 0;
            st.pop();
        }
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
            st.push(s[i]);
    }
    return st.empty();
}

int main(){
    string s = "()[]{}";
    cout << isValid(s);
}