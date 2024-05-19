// The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.
// The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.

#include <bits/stdc++.h>
using namespace std;

int LowerBound(vector<int> nums, int k){
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
    cout << LowerBound(nums, target);
}