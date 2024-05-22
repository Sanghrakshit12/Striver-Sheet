// Given an array of length N. Peak element is defined as the element greater than both of its neighbors. Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.
#include <bits/stdc++.h>
using namespace std;

// TC-O(N) SC-O(1)
// int Brute(vector<int> nums){
//     int n = nums.size();
//     if (nums[0] > nums[1])
//         return 0;
//     if (nums[n - 1] > nums[n - 2])
//         return n - 1;
//     for (int i = 1; i < n - 1; i++)
//     {
//         if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
//             return i;
//     }
//     return -1;
// }

int Peak(vector<int> nums){
    int n = nums.size();
    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;
    int l = 1, h = n - 2;
    while (l <= h){
        int m = l + (h - l) / 2;
        if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1])
            return m;
        else if (nums[m] > nums[m - 1] && nums[m] < nums[m + 1])
            l = m + 1;
        else
            h = m - 1;
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
    int x = Peak(nums);
    cout << x;
}
