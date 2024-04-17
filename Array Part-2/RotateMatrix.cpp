#include <bits/stdc++.h>
using namespace std;

void BruteForce_App(vector<vector<int>> &matrix){
    int n = matrix.size();
    vector<vector<int>> nums(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
          nums[j][n - i - 1] = matrix[i][j];
    }
    cout << "Rotated Matrix" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << nums[i][j] << " ";
        cout << endl;
    }
}

// Optimal Approach
void Optimal_App(vector<vector<int>> &matrix){
    int n = matrix[0].size();
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);
    }
    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}

int main(){
    int n;
    std::cout << "Enter Size of Matrix" << endl;
    cin >> n;
    vector<vector<int>> nums;
    for (int i = 0; i < n; i++){
        vector<int> nums1;
        for (int j = 0; j < n; j++){
            int a;
            cin >> a;
            nums1.push_back(a);
        }
        nums.push_back(nums1);
    }
    cout << "initial Matrix" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << nums[i][j] << " ";
        cout << endl;
    }
    Optimal_App(nums);
    // BruteForce_App(nums);
    cout << "Rotated Matrix" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << nums[i][j] << " ";
        cout << endl;
    }
}