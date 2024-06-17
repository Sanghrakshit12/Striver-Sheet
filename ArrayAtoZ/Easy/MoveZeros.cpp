#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums){
    int n = nums.size();
    int c = 0;
    for (int i = 0; i < n; i++){
        if (nums[i] != 0){
            swap(nums[i], nums[c]);
            c++;
        }
    }
}

int main(){
    vector<int> nums = {0, 2, 0, 4, 5};
    moveZeroes(nums);
    for(auto i:nums)
    cout<<i<<" ";
}