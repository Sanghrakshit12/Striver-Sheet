// IDEA - Max length Subarray with atmost 2 Fruits

#include <bits/stdc++.h>
using namespace std;

int Brute(vector<int> nums)
{
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        set<int> s;
        for (int h = i; h < n; h++)
        {
            s.insert(nums[h]);
            if (s.size() > 2)
                break;
            res = max(res, h - i + 1);
        }
    }
    return res;
}

int Optimal(vector<int> nums)
{
    int n = nums.size();
    int l = 0, r = 0, res = 0;
    unordered_map<int, int> mpp;
    while (r < n)
    {
        mpp[nums[r]]++;
            while (mpp.size() > 2){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            res = max(res, r - l + 1);
            r++;     
    }
     return res;
}

int main()
{
    vector<int> nums = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << Brute(nums);
}