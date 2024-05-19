#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> nums, int k){
    int n = nums.size();
    int l = 0, h = n - 1;
    while (l <= h){
        int m = l + (h - l) / 2;
        if (nums[m] == k)
            return m;
        else if (nums[m] > k)
            h = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int RecursiveBinary(vector<int> nums, int k, int l, int h)
{
    if (l > h)  return -1;
    int m = l + (h - l) / 2;
    if (nums[m] == k)
        return m;
    else if (nums[m] > k)
        return RecursiveBinary(nums, k, l, m - 1);
    else
        return RecursiveBinary(nums, k, m + 1, h);
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
    cout << BinarySearch(nums, target);
    cout<<endl;
    cout << RecursiveBinary(nums, target, 0, n - 1);
}