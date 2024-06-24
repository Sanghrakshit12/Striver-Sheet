#include <bits/stdc++.h>
using namespace std;

// int Brute(vector<int> nums, int k){
//     int n = nums.size();
//     int l = INT_MIN, h = 0;
//     for (int i = 0; i < n; i++){
//         l = max(l, nums[i]);
//         h += nums[i];
//     }
//     for (int i = l; i <= h; i++){
//         int cnt = 1, c = 0;
//         for (int j = 0; j < n; j++){
//             if (c + nums[j] <= i)
//                 c += nums[j];
//             else{
//                 c = nums[j];
//                 cnt++;
//             }
//         }
//         if (cnt == k)
//             return i;
//     }
//     return -1;
// }

int splitArray(vector<int> &nums, int k){
    int n = nums.size();
    int l = INT_MIN, h = 0;
    for (int i = 0; i < n; i++){
        l = max(nums[i], l);
        h += nums[i];
    }
    while (l <= h){
        int m = l + (h - l) / 2;
        int c = 0, cnt = 1;
        for (int i = 0; i < n; i++){
            if (nums[i] + c <= m)
                c += nums[i];
            else{
                cnt++;
                c = nums[i];
            }
        }
        if (cnt > k)
            l = m + 1;
        else
            h = m - 1;
    }
    return l;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;
    cout << splitArray(nums, k);
}