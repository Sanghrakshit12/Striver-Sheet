// Given 2 Sorted Array count all pairs where arr[i]>nums[j] where arr in array 1 and nums is array 2

#include <bits/stdc++.h>
using namespace std;

int CountPairs(vector<int> nums1, vector<int> nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    int i = 0, j = 0;
    int res = 0;
    while (i < n && j < m)
    {
        if (nums2[j] < nums1[i])
        {
            res += n - i;
            j++;
        }
        else
            i++;
    }
    return res;
}

int main()
{
    cout << "Enter size" << endl;
    int n, m;
    cin >> n >> m;
    vector<int> nums;
    vector<int> nums1;
    cout << "Enter 1 Array" << endl;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << "Enter 2 Array" << endl;
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        nums1.push_back(b);
    }
    cout << "initial Arrays" << endl;
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
    for (auto i : nums1)
        cout << i << " ";
    cout << endl;
    cout << CountPairs(nums, nums1);
}