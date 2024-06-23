#include <bits/stdc++.h>
using namespace std;

// int Brute(vector<int> nums, int k){
//     int n = nums.size();
//     sort(nums.begin(), nums.end());
//     for (int i = 1; i <= nums[n - 1] - nums[0]; i++){
//         int cnt = 1, back = nums[0];
//         bool b = 0;
//         for (int j = 1; j < n; j++){
//             if (nums[j] - back >= i){
//                 cnt++;
//                 back = nums[j];
//             }
//             if (cnt == k){
//                 b = 1;
//                 break;
//             }
//         }
//         if (b != 1)
//             return i - 1;
//     }
//     return 0;
// }

int BinaryApp(vector<int> nums, int k){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int l = 0, h = nums[n - 1] - nums[0], res = INT_MIN;
    while (l <= h){
        int m = l + (h - l) / 2;
        int cnt = 1, back = nums[0];
        bool b = 0;
        for (int i = 1; i < n; i++){
            if (nums[i] - back >= m){
                cnt++;
                back = nums[i];
            }
            if (cnt >= k){
                b = 1;
                break;
            }
        }
        if (b == 1){
            res = max(res, m);
            l = m + 1;
        }
        else
            h = m - 1;
    }
    return h;
}

int main(){
    vector<int> nums = {0, 3, 4, 7, 10, 9};
    int k = 4;
    cout << BinaryApp(nums, k);
}