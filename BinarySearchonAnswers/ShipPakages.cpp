#include <bits/stdc++.h>
using namespace std;

// int Brute(vector<int> nums, int k){
//     int n = nums.size();
//     int l = INT_MIN, h = 0;
//     for (int i = 0; i < n; i++){
//         l = max(nums[i], l);
//         h += nums[i];
//     }
//     for (int i = l; i <= h; i++){
//         int s = 0, res = 0;
//         for (int j = 0; j < n; j++){
//             if (s + nums[j] <= i)
//                 s += nums[j];
//             else{
//                 res++;
//                 s = nums[j];
//             }
//         }
//         if (res + 1 <= k)
//             return i;
//     }
//     return -1;
// }

int shipWithinDays(vector<int> &nums, int k){
    int n = nums.size();
    int l = INT_MIN, h = 0;
    for (int i = 0; i < n; i++){
        l = max(nums[i], l);
        h += nums[i];
    }
    while(l<=h){
        int m=l+(h-l)/2;
        int sum=0,res=1;
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=m)
                sum+=nums[i];
            else{
                res++;
                sum=nums[i];
            }
        }
        if(res<=k) h=m-1;
        else l=m+1;
    }
    return l;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 5;
    cout << shipWithinDays(nums, n);
}