// Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.
#include <bits/stdc++.h>
using namespace std;

// if array has no duplicates
// vector<int> Brute(vector<int> v){
//     sort(v.begin(), v.end());
//     return {v[1], v[v.size() - 2]};
// }

// TC-O(n)+O(n) SC-O(1)  Two Traversal of array required

// vector<int> SecondS(vector<int> nums){
//     int n = nums.size();
//     if (n < 2)
//         return {-1, -1};

//     int mn = INT_MAX, mx = INT_MIN;
//     for (int i = 0; i < n; i++){
//         mn = min(mn, nums[i]);
//         mx = max(mx, nums[i]);
//     }

//     int secondSmallest = INT_MAX, secondLargest = INT_MIN;
//     bool foundSecondSmallest = false, foundSecondLargest = false;

//     for (int i = 0; i < n; i++){
//         if (nums[i] > mn && nums[i] < secondSmallest){
//             secondSmallest = nums[i];
//             foundSecondSmallest = true;
//         }
//         if (nums[i] < mx && nums[i] > secondLargest){
//             secondLargest = nums[i];
//             foundSecondLargest = true;
//         }
//     }

//     if (!foundSecondSmallest)
//         secondSmallest = -1;
//     if (!foundSecondLargest)
//         secondLargest = -1;

//     return {secondSmallest, secondLargest};
// }


vector<int> Optimal(vector<int> a)
{
    int n = a.size();
    int largest = a[0], secondLargest = -1;
    int smallest = a[0], secondSmallest = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > largest)
        {
            secondLargest = largest;
            largest = a[i];
        }
        else if (a[i] > secondLargest && a[i] < largest)
        {
            secondLargest = a[i];
        }

        if (a[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = a[i];
        }
        else if (a[i] < secondSmallest && a[i] > smallest)
        {
            secondSmallest = a[i];
        }
    }

    // cout << secondLargest << " " << secondSmallest << endl;

    return {secondLargest, secondSmallest};
}

int main()
{
    vector<int> v = {2, 2, 2, 2};
    // vector<int> res1 = Brute(v);
    // for (auto x : res1)
    //     cout << x << " ";
    vector<int> res1 = Optimal(v);
    for (auto x : res1)
        cout << x << " ";
}