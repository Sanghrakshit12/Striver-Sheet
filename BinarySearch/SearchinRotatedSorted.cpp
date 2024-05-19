// Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.

#include <bits/stdc++.h>
using namespace std;

int Search(vector<int> nums, int k){
    int n = nums.size();
    int l = 0, h = n - 1;
    while (l <= h){
        int m = l + (h - l) / 2;
        if (nums[m] == k) return m;
        else if (nums[m] >= nums[l]){
            if (k >= nums[l] && k < nums[m])
                h = m - 1;
            else
                l = m + 1;
        }
        else{
            if (k > nums[m] && k <= nums[h])
                l = m + 1;
            else
                h = m - 1;
        }
    }
    return -1;
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
    int target;
    cout << "Enter Target" << endl;
    cin >> target;
    int x = Search(nums, target);
    cout << x;
}