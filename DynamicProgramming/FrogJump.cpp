#include <bits/stdc++.h>
using namespace std;

int frogjump(vector<int> v, int n)
{
 if(n==0) return 0;
 int l=frogjump(v,n-1)+abs(v[n]-v[n-1]);
  int r=INT_MAX;
 if(n>1) r=frogjump(v,n-2)+abs(v[n]-v[n-2]);
 return min(l,r);
}

int main()
{
    vector<int> v = {10, 20, 30, 10};
    int n;
    cin >> n;
    cout<<frogjump(v, n);
}