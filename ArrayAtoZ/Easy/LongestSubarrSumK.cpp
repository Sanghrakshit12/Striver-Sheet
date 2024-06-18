// Given an array containing N integers and an integer K Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.
// Positives only

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
// int Better(vector<int> nums, int K){
//     unordered_map<int, int> mpp;
//     int n = nums.size();
//     int sum = 0, res = 0;
//     for (int i = 0; i < n; i++){
//         sum += nums[i];
//         if (sum == K)
//             res = max(res, i + 1);
//         if (mpp.find(sum - K) != mpp.end())
//             res = max(res, i - mpp[sum - K]);
//         if (mpp.find(sum) == mpp.end())
//             mpp[sum] = i;
//     }
//     return res;
// }


// Optimal Soln 2 pointer
int Optimal(vector<int> &a, long long k){
    int n = a.size();
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
    while (right < n){
        while (left <= right && sum > k){
            sum -= a[left];
            left++;
        }
        if (sum == k)
            maxLen = max(maxLen, right - left + 1);
        right++;
        if (right < n)
            sum += a[right];
    }
    return maxLen;
}


int main()
{
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k;
    cin >> k;
    cout << Optimal(nums, k);
}