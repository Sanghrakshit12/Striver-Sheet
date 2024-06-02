// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position. Return true if you can reach the last index, or false otherwise.

#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums){
    int n = nums.size();
    int maxidx = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxidx >= n - 1)
            return 1;
        if (i > maxidx)
            return 0;
        maxidx = max(maxidx, i + nums[i]);
    }
    return 1;
}

int main()
{
    vector<int> nums = {3,2,1,0,4};
    cout << canJump(nums);
}