#include <bits/stdc++.h>
using namespace std;

// TC-O(2^n*n) SC-O(n)
bool Subsequence(vector<int> nums, int idx, vector<int> &res, int k, int sum){
    if (idx >= nums.size()){
        if (sum == k){
            for (int i = 0; i < res.size(); i++)
                cout << res[i] << " ";
            cout << endl;
            return 1;
        }
        return 0;
    }
    res.push_back(nums[idx]);
    sum += nums[idx];
    if (Subsequence(nums, idx + 1, res, k, sum))
        return 1;
    sum -= nums[idx];
    res.pop_back();
    if (Subsequence(nums, idx + 1, res, k, sum))
        return 1;
    return 0;
}

int main(){
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