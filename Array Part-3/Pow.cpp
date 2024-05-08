#include <bits/stdc++.h>
using namespace std;

long long Brute(double x, int n){
    bool b = 0;
    long long num, res = 1;
    if (n < 0)
    {
        num = (-1) * n;
        b = 1;
    }
    else
    {
        num = n;
    }
    for (int i = 1; i <= num; i++)
    {
        res *= x;
    }
    if(b==0)
    return res;
    else
    return 1/res;
}

int main()
{
    double x;
    int n;
    cout << "Enter the Values" << endl;
    cin >> x >> n;
    cout << Brute(x, n);
}