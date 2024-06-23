#include <bits/stdc++.h>
using namespace std;

// O(n*max(nums[i]))  O(1)
// int Brute(vector<int> nums, int k){
//     int n = nums.size();
//     int mx = INT_MIN, mn = 1, res = INT_MAX;
//     for (int i = 0; i < n; i++)
//         mx = max(mx, nums[i]);
//     for (int i = mn; i <= mx; i++){
//         int x = 0;
//         for (int j = 0; j < n; j++)
//             x += ceil((double)nums[j] / i);
//         if (x <= k)
//             return i;
//     }
//     return -1;
// }


// O( n* log max(nums[i]))  O(1)
int minEatingSpeed(vector<int> &nums, int k){
    int n = nums.size();
    int mx = INT_MIN, mn = 1, res = INT_MAX;
    for (int i = 0; i < n; i++)
        mx = max(mx, nums[i]);
    while (mn <= mx){
        int m = mn + (mx - mn) / 2;
        long long x = 0;
        for (int j = 0; j < n; j++)
            x += ceil((double)nums[j] / (double)m);
        if (x <= k)
            mx = m - 1;
        else
            mn = m + 1;
    }
    return mn;
}

int main()
{
    vector<int> piles = {7, 15, 6, 3};
    int h = 8;
    cout << minEatingSpeed(piles, h);
}