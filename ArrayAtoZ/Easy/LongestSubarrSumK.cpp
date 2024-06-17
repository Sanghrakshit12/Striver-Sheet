// Given an array containing N integers and an integer K Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

#include <bits/stdc++.h>
using namespace std;

// O(N^3)
// int Brute(vector<int> nums, int K)
// {
//     int res=INT_MIN;
//     int n=nums.size();
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             int s=0;
//             for(int k=i;k<=j;k++){
//                 s+=nums[k];
//             }
//             if(s==K){
//                 res=max(res,j-i+1);
//                 break;
//             }
//         }
//     }
//     return (res==INT_MIN)? 0: res;
// }

// O(n^2)
// int Brute2(vector<int> nums, int K){
//     int res = INT_MIN;
//     int n = nums.size();
//     for (int i = 0; i < n; i++){
//         int s = 0;
//         for (int j = i; j < n; j++){
//             s += nums[j];
//             if (s == K){
//                 res = max(res, j - i + 1);
//                 break;
//             }
//         }
//     }
//     return (res == INT_MIN) ? 0 : res;
// }

// Using Hashing
int Better(vector<int>nums,int K){
    unordered_map<int,int>mpp;
    int s=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        s+=nums[i];
        mpp[i]=s;
    }
    s=0;
    for(int i=0;i<n;i++){
        s+=nums[i];
        if(mpp.find(K-s)!=mpp.end()){

        }
    }
}

int main()
{
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k;
    cin >> k;
    cout << Better(nums, k);
}