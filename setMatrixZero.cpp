#include <bits/stdc++.h>
using namespace std;

// Brute Force
// vector<vector<int>> setMatrixZero(int n, int m, vector<vector<int>> nums){
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++){
//             if (nums[i][j] == 0){
//                 for (int k = 0; k < m; k++){
//                     if (nums[i][k] != 0)  nums[i][k] = -1;
//                 }
//                 for (int k = 0; k < n; k++) {
//                     if (nums[k][j] != 0)  nums[k][j] = -1;
//                 }
//             }
//         }
//     }
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++){
//             if (nums[i][j] == -1)  nums[i][j] = 0;
//         }
//     }
//     cout << "Final MAtrix" << endl;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++){
//             cout << nums[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return nums;
// }

// Better Approach
// vector<vector<int>> setMatrixZero(int n, int m, vector<vector<int>> nums){
//     vector<int> row(n, 0);
//     vector<int> col(m, 0);
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++) {
//             if (nums[i][j] == 0){
//                 row[i] = 1;
//                 col[j] = 1;
//             }
//         }
//     }
//        for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (row[i] || col[j]) {
//                 nums[i][j] = 0;
//             }
//         }
//     }
//        cout << "Final MAtrix" << endl;
//        for (int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++){
//             cout << nums[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

vector<vector<int>> setMatrixZero(int n, int m, vector<vector<int>> nums)
{
    int help = -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if (nums[i][j] == 0){
                if (i == 0)  help = 0;
                else         nums[i][0] = 0;
                nums[0][j] = 0;
            }
        }
    }
    for (int i = n - 1; i >= 1; i--){
        for (int j = m - 1; j >= 1; j--) {
            if (nums[0][j] == 0 || nums[i][0] == 0) {
                nums[i][j] = 0;
            }
        }
    }
    if (nums[0][0] == 0){
        for (int i = 0; i < n; i++)
            nums[i][0] = 0;
    }
    if (help == 0){
        for (int i = 0; i < m; i++)
            nums[0][i] = 0;
    }
       cout << "Final MAtrix" << endl;
       for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
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
    cout << "initial Matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    setMatrixZero(n, m, nums);
}