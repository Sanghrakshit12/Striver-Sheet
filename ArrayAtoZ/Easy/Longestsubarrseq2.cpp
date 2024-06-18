// Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.
// (Positive and negative elements Included)

#include <bits/stdc++.h>
using namespace std;

// O(n^3)
// int Brute1(vector<int> nums,int K){
//     int n=nums.size();
//     int res=0;
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int sum=0;
//             for(int k=i;k<=j;k++){
//                 sum+=nums[k];
//             }
//             if(sum==K)
//                 res=max(res,j-i+1);
//         }
//     }
//     return res;
// }

// O(n^2)
// int Brute2(vector<int> nums, int K){
//     int n = nums.size();
//     int res = 0;
//     for (int i = 0; i < n; i++){
//         int sum = 0;
//         for (int j = i; j < n; j++){
//             sum+=nums[j];
//             if(sum==K) res=max(res,j-i+1);
//         }
//     }
//     return res;
// }

 // O(n) O(n)
int Optimal(vector<int> nums, int K){
    unordered_map<int,int>mpp;
    int n=nums.size();
    int sum=0,res=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(sum==K) res=max(res,i+1);
        if(mpp.find(sum-K)!=mpp.end())
            res=max(res,i-mpp[sum-K]);
        if(mpp.find(sum)==mpp.end())
        mpp[sum]=i;
    }
    return res;
}

int main(){
    vector<int> nums = {-1, 1, 1};
    int k;
    cin >> k;
    cout << Optimal(nums, k);
}