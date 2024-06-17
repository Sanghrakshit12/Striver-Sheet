#include <bits/stdc++.h>
using namespace std;

int Brute(vector<int>nums){
    int n=nums.size();
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++)
        mpp[nums[i]]++;
    for(auto i:mpp)
        if(i.second==1) return i.first;
    return -1;
}

int singleNumber(vector<int> &nums){
    int x = nums[0];
    for (int i = 1; i < nums.size(); i++)
        x = x ^ nums[i];
    return x;
}

int main()
{
    vector<int> nums={2,2,3,4,3,4,9};
    cout<<singleNumber(nums)<<" "<<Brute(nums);
}