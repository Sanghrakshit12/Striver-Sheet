#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x=n;
    int c = 0,s=0;
    while (n > 0)
    {
        c=n%10;
        s=(s*10)+c;
        n /= 10;
    }
    if(s==x) cout<<"1";
    else cout<<"0";
} 