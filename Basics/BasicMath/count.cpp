#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int c = 0;
    cout<< (int)(log10(n) + 1)<<endl;
    
    while (n > 0)
    {
        c++;
        n /= 10;
    }
    cout << c;
}