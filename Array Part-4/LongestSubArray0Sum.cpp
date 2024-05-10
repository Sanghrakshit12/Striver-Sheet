#include <bits/stdc++.h>
using namespace std;

// int Brute(vector<int> nums)
// {
//     int n = nums.size();
//     int res = 1;
//     for (int i = 0; i < n; i++){
//         for (int j = i + 1; j < n; j++){
//             int s = 0;
//             for (int k = i; k <= j; k++)
//                 s += nums[k];
//             if (s == 0)
//                 res = max(res, j - i + 1);
//         }
//     }
//     return res;
// }

// int Better(vector<int> nums){
//     int n = nums.size();
//     int res = 1;
//     for (int i = 0; i < n; i++){
//         int s = 0;
//         for (int j = i; j < n; j++){
//             s += nums[j];
//             if (s == 0)
//                 res = max(res, j - i + 1);
//         }
//     }
//     return res;
// }

int Optimal(vector<int> nums)
{
    int n = nums.size();
    unordered_map<int, int> mpp;
    int s = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        s += nums[i];
        if (s == 0)
        {
            res = max(res, i + 1);
        }
        else
        {
            if (mpp.find(s) != mpp.end())
                res = max(res, i - mpp[s]);
            else
                mpp[s] = i;
        }
    }
    return res;
}

int main()
{
    cout << "Enter size" << endl;
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << "initial Matrix" << endl;
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
    cout << Optimal(nums);
}
