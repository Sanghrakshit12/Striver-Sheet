#include <bits/stdc++.h>
using namespace std;

// int Brute(vector<int> nums){
//     int n = nums.size();
//     int res = nums[0];
//     for (int i = 0; i < n; i++){
//         for (int j = i; j < n; j++){
//             int prod = 1;
//             for (int k = i; k <= j; k++)
//                 prod = prod * nums[k];
//             res = max(prod, res);
//         }
//     }
//     return res;
// }

// int Brute2(vector<int> nums){
//     int n = nums.size();
//     int res = nums[0];
//     for (int i = 0; i < n; i++){
//         int prod = 1;
//         for (int j = i; j < n; j++){
//             prod = prod * nums[j];
//             res = max(res, prod);
//         }
//     }
//     return res;
// }

int Optimal(vector<int> nums){
    int n = nums.size();
    long long pre = 1;
    long long suf = 1;
    int res = INT_MIN;
    for (int i = 0; i < n; i++){
        if (pre == 0)
            pre = 1;
        if (suf == 0)
            suf = 1;
        pre *= nums[i];
        suf *= nums[n - i - 1];
        res = max(res, (int)max(pre, suf));
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 2, -3, 0, -4, -5};
    cout << Optimal(nums);
}