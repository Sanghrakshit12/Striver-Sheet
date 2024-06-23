#include <bits/stdc++.h>
using namespace std;

// int Brute(vector<int> nums, int k){
//     int n=nums.size();
//     if (n < k)
//         return -1;
//     int mx = INT_MIN, s = 0;
//     for (int i = 0; i < n; i++){
//         mx = max(mx, nums[i]);
//         s += nums[i];
//     }
//     for (int i = mx; i <= s; i++){
//         int x = 0, cnt = 1;
//         bool b = 1;
//         for (int j = 0; j < n; j++){
//             if (x + nums[j] <= i)
//                 x += nums[j];
//             else{
//                 cnt++;
//                 x = nums[j];
//             }
//         }
//         if (cnt <= k)
//             return i;
//     }
//     return -1;
// }

int findPages(vector<int> nums, int k){
    int n = nums.size();
    if (n < k)
        return -1;
    int l = INT_MIN, h = 0;
    for (int i = 0; i < n; i++){
        l = max(l, nums[i]);
        h += nums[i];
    }
    while (l <= h){
        int m = l + (h - l) / 2;
        int x = 0, cnt = 1;
        for (int i = 0; i < n; i++){
            if (nums[i] + x <= m)
                x += nums[i];
            else{
                cnt++;
                x = nums[i];
            }
        }
        if (cnt <= k)
            h = m - 1;
        else
            l = m + 1;
    }
    return l;
}


int main()
{
    vector<int> nums = {12, 34, 67, 90};
    int k = 2;
    cout << findPages(nums, k);
}