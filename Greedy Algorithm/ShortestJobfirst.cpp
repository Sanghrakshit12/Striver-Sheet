#include <bits/stdc++.h>
using namespace std;

int AvgWaitingtime(vector<int> nums){
    int wt = 0, t = 0;
    sort(nums.begin(),nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++){
        wt += t;
        t += nums[i];
    }
    return floor(wt / n);
}

int main(){
    vector<int> nums = {4, 3, 7, 1, 2};
    cout << AvgWaitingtime(nums);
}