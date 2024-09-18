
// Idea -> we find the longest subarray with atmost k zeros

#include <bits/stdc++.h>
using namespace std;

int Brute(vector<int> nums, int x)
{
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int c = 0;
            for (int k = i; k <= j; k++)
            {
                if (nums[k] == 0)
                    c++;
            }
            if (c <= x)
                res = max(res, j - i + 1);
        }
    }
    return res;
}

int Brute2(vector<int> nums, int x)
{
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        for (int j = i; j < n; j++)
        {
            if (nums[j] == 0)
                c++;
            if (c <= x)
                res = max(res, j - i + 1);
            else
                break;
        }
    }
    return res;
}

int Better(vector<int> nums, int x)
{
    int n = nums.size();
    int l = 0, r = 0, res = 0, c = 0;
    while (r < n)
    {
        if (nums[r] == 0)
            c++;
        while (c > x)
        {
            if(nums[l]==0) c--;
            l++;
        }
        res = max(res, r - l + 1);
        r++;
    }
    return res;
}

int Optimal(vector<int> nums, int x)
{
    int n=nums.size();
    int r=0,l=0,res=0,c=0;
    while(r<n){
        if(nums[r]==0) c++;
        if(c<=x){ 
            res=max(res,r-l+1);
        }
        else{
            if(nums[l]==0) c--;
            l++;
        }
        r++;
    }
    return res;
}

int main()
{
    int k = 2;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << Optimal(nums, k);
}