#include <bits/stdc++.h>
using namespace std;

// int Brute(vector<int> nums, int k, int m){
//     int h = INT_MIN, l = INT_MAX;
//     int n = nums.size();
//     if (k * m > n)
//         return -1;
//     for (int i = 0; i < n; i++){
//         h = max(h, nums[i]);
//         l = min(l, nums[i]);
//     }
//     for (int i = l; i <= h; i++){
//         int c = 0, res = 0;
//         for (int j = 0; j < n; j++){
//             if (nums[j] <= i)
//                 c++;
//             else{
//                 res += (c / k);
//                 c = 0;
//             }
//         }
//         res += (c / k);
//         if (res >= m)
//             return i;
//     }
//     return -1;
// }

int minDays(vector<int> &nums, int m, int k){
    int n = nums.size();
    long long val = (1ll) * k * m * 1ll;
    if (val > n)
        return -1;
    int l = INT_MAX, h = INT_MIN;
    for (int i = 0; i < n; i++){
        l = min(nums[i], l);
        h = max(nums[i], h);
    }
    while (l <= h){
        int md = l + (h - l) / 2;
        int c = 0, res = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] <= md)
                c++;
            else{
                res += (c / k);
                c = 0;
            }
        }
        res += (c / k);
        if (res >= m)
            h = md - 1;
        else
            l = md + 1;     
    }
    return l;
}

int main(){
    vector<int> nums = {7, 7, 7, 7, 13, 11, 12, 7};
    int n, k, m;
    n = 8, m = 2, k = 3;
    cout << minDays(nums, m, k);
}