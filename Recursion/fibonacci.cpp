#include <bits/stdc++.h>
using namespace std;

int fibofn(int n){
if(n==1) return 0;
if(n==2) return 1;
return fibofn(n-1)+fibofn(n-2);
}

int fibo(int n)
{
    if(n==1) return 0;
    if(n==2) return 1;
    int sum = 0,res=1;
    int p = 0, c = 1;
    for (int i = 3; i <= n; i++)
    {
        sum = p + c;
        res+=sum;
        p = c;
        c = sum;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout<<fibo(n)<<endl;
    cout<<fibofn(n);
}