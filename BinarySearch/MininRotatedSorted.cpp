// Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array.

#include <bits/stdc++.h>
using namespace std;

int Mini(vector<int> nums){
    int n = nums.size();
    int l = 0, h = n - 1, mini = INT_MAX;
    while (l <= h){
        int m = l + (h - l) / 2;
          if (nums[m] <= nums[h]){
            mini = min(mini, nums[m]);
            h = m - 1;
        }
        if (nums[m] <= nums[h]){
            mini = min(mini, nums[m]);
            h = m - 1;
        }
        else{
            mini = min(mini, nums[l]);
            l = m + 1;
        }
    }
    return mini;
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
    int x = Mini(nums);
    cout << x;
}
