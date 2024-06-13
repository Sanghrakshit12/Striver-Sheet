#include <bits/stdc++.h>
using namespace std;

// TC-O(2^n*n) SC-O(n)
int Subsequence(vector<int> nums, int idx, int k, int sum){
    if (idx >= nums.size()){
        if (sum == k)
            return 1;
        return 0;
    }
    sum += nums[idx];
    int l = Subsequence(nums, idx + 1, k, sum);
    sum -= nums[idx];
    int r = Subsequence(nums, idx + 1, k, sum);
    return l + r;
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
    cout << Subsequence(nums, 0, k, 0);
}