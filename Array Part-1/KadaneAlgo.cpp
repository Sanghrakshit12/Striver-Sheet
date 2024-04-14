#include <bits/stdc++.h>
using namespace std;

// int BruteForce(vector<int> v){
//     int n = v.size();
//     int res = INT_MIN;
//     for (int i = 0; i < n; i++){
//         for (int j = i; j < n; j++) {
//             int sum = 0;
//             for (int k = i; k <= j; k++)  sum += v[k];
//             res = max(res, sum);
//         }
//     }
//     return res;
// }

// Better Approach
// int BetterApp(vector<int> v){
//     int n = v.size();
//     int res = INT_MIN;
//     for (int i = 0; i < n; i++){
//          int sum = 0;
//         for (int j = i; j < n; j++) {
//             sum += v[j];
//             res = max(res, sum);
//         }
//     }
//     return res;
// }

int maxSubArray(vector<int> &nums){
    int n = nums.size();
    int sum = 0, res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        res = max(res, sum);
        if (sum < 0)
            sum = 0;
    }
    return res;
}

int main()
{
    vector<int> v;
    cout << "Enter Size of Vector" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << maxSubArray(v);
}
