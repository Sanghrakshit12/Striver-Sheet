// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where: 0 <= j <= nums[i] and i + j < n Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums){
    int n = nums.size();
    int l = 0, r = 0, jumps = 0;
    while (r < n - 1){
        int far = 0;
        for (int j = l; j <= r; j++)
            far = max(far, nums[j] + j);
        l = r + 1;
        r = far;
        jumps++;
    }
    return jumps;
}


int main(){
    vector<int> nums = {2,3,1,1,4};
    cout << jump(nums);
}