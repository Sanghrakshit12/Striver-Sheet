#include <bits/stdc++.h>
using namespace std;

// TC-O(2^n*n) SC-O(n)
void Subsequence(vector<int> nums, int idx, vector<int> &res, int k, int sum = 0)
{
    if (idx >= nums.size())
    {
        if (sum == k)
        {
            for (int i = 0; i < res.size(); i++)
                cout << res[i] << " ";
            cout<<endl;
        }
        return;
    }
    res.push_back(nums[idx]);
    Subsequence(nums, idx + 1, res, k, sum + nums[idx]);
    res.pop_back();
    Subsequence(nums, idx + 1, res, k, sum);
}

int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<int> x;
    Subsequence(nums, 0, x, k, 0);
}