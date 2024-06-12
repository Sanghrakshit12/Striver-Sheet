#include <bits/stdc++.h>
using namespace std;

// Parameterized way
void sum(int c, int s){
    if (c < 1){
        cout << s;
        return;
    }
    sum(c - 1, s + c);
}

// Functional Way

int sumfn(int n){
    if(n==1) return 1;
    return n+sumfn(n-1);
}

int main(){
    int n;
    cin >> n;
    sum(n, 0);
    cout<<endl;
    cout<<sumfn(n);
}
