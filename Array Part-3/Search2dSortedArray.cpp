#include <bits/stdc++.h>
using namespace std;

// bool Brute(vector<vector<int>> nums, int k){
//     int n = nums.size();
//     for (int i = 0; i < n; i++){
//         int m = nums[i].size();
//         for (int j = 0; j < m; j++){
//             if (nums[i][j] == k)
//                 return 1;
//         }
//     }
//     return 0;
// }

bool Better(vector<vector<int>> nums, int k){
    int n = nums.size();
    for (int i = 0; i < n; i++){
        int m = nums[i].size();
        int x = nums[i][0], y = nums[i][m - 1];
        if (k >= x && k <= y){
            int l = 0, h = m - 1;
            while (l <= h){
                int m = l + (h - l) / 2;
                if (k > nums[i][m])
                    l = m + 1;
                else if (k < nums[i][m])
                    h = m - 1;
                else
                    return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n, m;
    std::cout << "Enter Size of Matrix" << endl;
    cin >> n >> m;
    vector<vector<int>> nums;
    for (int i = 0; i < n; i++)
    {
        vector<int> nums1;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            nums1.push_back(a);
        }
        nums.push_back(nums1);
    }
    int k;
    cout << "Enter Element to Be Searched" << endl;
    cin >> k;
    cout << "initial Matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << nums[i][j] << " ";
        cout << endl;
    }
    cout << Better(nums, k);
}