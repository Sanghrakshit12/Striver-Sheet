// Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums){
    int n = nums.size();
    int c = 0, res = 0;
    for (int i = 0; i < n; i++){
        if (nums[i] == 1)
            c++;
        else
            c = 0;
        res = max(res, c);
    }
    return res;
}

int main(){
    vector<int> nums = {1, 1, 0, 1, 1, 1, 1, 1};
    cout << findMaxConsecutiveOnes(nums);
}