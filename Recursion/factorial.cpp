#include <bits/stdc++.h>
using namespace std;

// Parameterized way
void fact(int f, int n)
{
    if (n < 1)
    {
        cout << f << endl;
        return;
    }
    fact(f*n,n-1);
}

// Functional Way

int factfn(int n){
    if(n==1) return 1;
    return n*factfn(n-1);
}

int main()
{
    int n;
    cin >> n;
    fact(1, n);
    cout<<factfn(n);
}
