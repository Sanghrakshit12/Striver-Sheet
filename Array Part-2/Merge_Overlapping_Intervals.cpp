#include <bits/stdc++.h>
using namespace std;

// BruteForce Approach
// void BruteForce_App(vector<vector<int>> &nums)
// {
// sort(nums.begin(),nums.end());
//     int n = nums.size();
//     vector<vector<int>> res;
//     for (int i = 0; i < n; i++){
//         int s = nums[i][0];
//         int e = nums[i][1];
//         if (!res.empty() && e <= res.back()[1])  continue;
//         for (int j = i + 1; j < n; j++){
//             if (nums[j][0] <= e)
//                 e = max(e, nums[j][1]);
//             else
//                 break;
//         }
//         res.push_back({s, e});
//     }
//     cout << "Final Matrix" << endl;
//     for (int i = 0; i < res.size(); i++){
//         for (int j = 0; j < 2; j++)
//             cout << res[i][j] << " ";
//         cout << endl;
//     }
// }

// Optimal Approach
//     vector<vector<int>> merge(vector<vector<int>> &nums)
// {
//     int n = nums.size();
//     sort(nums.begin(), nums.end());
//     vector<vector<int>> res;
//     for (int i = 0; i < n; i++)
//     {
//         if (res.empty() || nums[i][0] > res.back()[1])
//             res.push_back(nums[i]);
//         else
//             res.back()[1] = max(res.back()[1], nums[i][1]);
//     }
//     return res;
// }


int main()
{
    cout << "Enter Rows" << endl;
    int n;
    cin >> n;
    vector<vector<int>> nums;
    for (int i = 0; i < n; i++)
    {
        vector<int> nums1;
        for (int j = 0; j < 2; j++)
        {
            int a;
            cin >> a;
            nums1.push_back(a);
        }
        nums.push_back(nums1);
    }
    cout << "initial Matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << nums[i][j] << " ";
        cout << endl;
    }
    // BruteForce_App(nums);
    // merge(nums)
}