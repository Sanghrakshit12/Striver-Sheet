#include <bits/stdc++.h>
using namespace std;

// int Brute(vector<int> nums, int k){
//     int n = nums.size();
//     for (int i = 0; i < n; i++){
//         if (nums[i] <= k)
//             k++;
//         else
//             return k;
//     }
//     return k;
// }

int findKthPositive(vector<int> &nums, int k){
    int n = nums.size();
    int l = 0, h = n - 1;
    while (l <= h){
        int m = l + (h - l) / 2;
        int val = nums[m] - (m + 1);
        if (val >= k)
            h = m - 1;
        else
            l = m + 1;
    }
    return k + h + 1;
}


int main()
{
    vector<int> nums = {2, 3, 4, 7, 11};
    int k = 5;
    cout << findKthPositive(nums, k);
}