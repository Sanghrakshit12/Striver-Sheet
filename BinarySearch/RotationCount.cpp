// Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated.

#include <bits/stdc++.h>
using namespace std;


// TC->O(N)
// int Brute(vector<int> nums){
//     int n = nums.size();
//     for (int i = 0; i < n - 1; i++){
//         if (nums[i] > nums[i + 1])
//             return i + 1;
//     }
//     return 0;
// }

// TC->O(logN)
int Rotation(vector<int> nums){
    int n = nums.size();
    int l = 0, h = n - 1, mini = INT_MAX, res = 0;
    while (l <= h){
        int m = l + (h - l) / 2;
        if (nums[l] <= nums[h]){
            if (mini > nums[l]){
                mini = nums[l];
                res = l;
            }
            break;
        }
        if (nums[l] <= nums[m]){
            if (nums[l] < mini){
                res = l;
                mini = nums[l];
            }
            l = m + 1;
        }
        else{
            if (nums[m] < mini){
                res = m;
                mini = nums[m];
            }
            h = m - 1;
        }
    }
    return res;
}

int main(){
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
    int x = Rotation(nums);
    cout << x;
}