// Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.
#include <bits/stdc++.h>
using namespace std;

int SecondLargest(vector<int> nums)
{
    int n = nums.size();
    int mx = nums[0], sm = -1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > mx)
        {
            sm = mx;
            mx = nums[i];
        }
    }
}

int SecondSmallest(vector<int> nums)
{
    int n = nums.size();
    int mx = nums[0], sm = -1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > mx)
        {
            sm = nums[i];
            mx 
        }
    }
}

int main()
{
    vector<int> v = {2, 5, 2, 6};
    cout << SecondSmallest(v) << endl;
    cout << SecondLargest(v);
}