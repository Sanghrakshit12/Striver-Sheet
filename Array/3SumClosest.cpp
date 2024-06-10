#include <bits/stdc++.h>
using namespace std;

int SumClose(vector<int> v, int k)
{
int n = v.size();
    int res = INT_MAX;
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = 0;
            for (int k = j + 1; k < n; k++)
            {
                sum = v[i] + v[j] + v[k];
            }
            if(res<k-sum){
                res=k-sum;
                ans=sum;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {-1, 2, 1, -4};
    cout << SumClose(v, 1);
}