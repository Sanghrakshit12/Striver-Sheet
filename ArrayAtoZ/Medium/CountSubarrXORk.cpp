#include <bits/stdc++.h>
using namespace std;

// int Brute(vector<int> nums, int K)
// {
//     int n = nums.size();
//     int c = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             int x = 0;
//             for (int k = i; k <= j; k++)
//                 x = x ^ nums[k];
//             if (x == K)
//                 c++;
//         }
//     }
//     return c;
// }

// int Brute2(vector<int> nums, int K){
//     int n = nums.size();
//     int res = 0;
//     for (int i = 0; i < n; i++){
//         int x = 0;
//         for (int j = i; j < n; j++){
//             x = x ^ nums[j];
//             if (x == K)
//                 res++;
//         }
//     }
//     return res;
// }

int Optimal(vector<int> nums, int K){
    int n = nums.size();
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int x = 0, res = 0;
    for (int i = 0; i < n; i++){
        x = x ^ nums[i];
        if (mpp.find(x ^ K) != mpp.end())
            res += mpp[x ^ K];
        mpp[x]++;
    }
    return res;
}

int main()
{
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;
    cout << Optimal(nums, k);
}