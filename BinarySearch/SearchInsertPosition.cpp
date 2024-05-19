// You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.
// If the value is present in the array, then return its index. Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.

#include <bits/stdc++.h>
using namespace std;

int Position(vector<int> nums, int k){
    int n = nums.size();
    int l = 0, h = n - 1, res = n;
    while (l <= h){
        int m = l + (h - l) / 2;
        if (nums[m] >= k){
            res = m;
            h = m - 1;
        }
        else
            l = m + 1;
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
    int target;
    cout << "Enter Target" << endl;
    cin >> target;
    cout << Position(nums, target);
}