#include <bits/stdc++.h>
using namespace std;

// int Brute(vector<int> nums, int k){
//     int n = nums.size();
//     int mx = INT_MIN;
//     for (int i = 0; i < n; i++)
//         mx = max(mx, nums[i]);
//     for (int i = 1; i <= mx; i++){
//         int x = 0;
//         for (int j = 0; j < n; j++)
//             x += ceil((double)nums[j] / i);
//         if (x <= k)
//             return i;
//     }
//     return -1;
// }

int smallestDivisor(vector<int> &nums, int k){
    int n = nums.size();
    int h = INT_MIN;
    for (int i = 0; i < n; i++)
        h = max(nums[i], h);
    int l = 1;
    while (l <= h){
        int x = 0;
        int m = l + (h - l) / 2;
        for (int i = 0; i < n; i++)
            x += ceil((double)nums[i] / m);
        if (x <= k)
            h = m - 1;
        else
            l = m + 1;
    }
    return l;
}

int main(){
    vector<int> nums = {1, 2, 5, 9};
    int k;
    k = 6;
    cout << smallestDivisor(nums, k);
}