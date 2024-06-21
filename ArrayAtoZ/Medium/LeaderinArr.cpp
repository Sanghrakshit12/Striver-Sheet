// Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.

#include <bits/stdc++.h>
using namespace std;

// O(n^2)  O(1)
vector<int> Brute(vector<int> nums)
{
    int n = nums.size();
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        bool f = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] < nums[j])
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
            res.push_back(nums[i]);
    }
    return res;
}

vector<int> OptimalLeader(vector<int> nums)
{
    int n = nums.size();
    vector<int> res;
    res.push_back(nums[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] >= res.back())
            res.push_back(nums[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> nums = {16, 17, 4, 3, 5, 2};
    vector<int> res = OptimalLeader(nums);
    for (auto i : res)
    {
        cout << i << " ";
    }
}