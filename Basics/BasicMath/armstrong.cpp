#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x=n;
    int s=0;
    while (n > 0)
    {
        int c=n%10;
        s+=(c*c*c);
        n /= 10;
    }
    if(s==x) cout<<"1";
    else cout<<"0";
}