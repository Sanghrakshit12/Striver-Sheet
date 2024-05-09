#include <bits/stdc++.h>
using namespace std;

// int Brute(vector<int> nums)
// {
//     int n = nums.size();
//     int c = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (nums[i] > (2 * nums[j]))
//                 c++;
//         }
//     }
//     return c;
// }

// if (nums[i] > 2 * nums[j])
//         {
//             res += h - i + 1;
//             j++;
//         }
//         else
//             i++;

void Merge(vector<int>& nums, int l, int m, int h)
{
    int i = l, j = m + 1;
    vector<int> temp;
    int res = 0;
    while (i <= m && j <= h)
    {
        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else
        {
            temp.push_back(nums[j]);
            j++;
        }
    }
    while (i <= m)
    {
        temp.push_back(nums[i]);
        i++;
    }
    while (j <= h)
    {
        temp.push_back(nums[j]);
        j++;
    }
    for (int k = l; k <= h; k++)
    {
        nums[k] = temp[k - l];
    }
}
int Pairs(vector<int> nums, int l, int m, int h)
{
    int cnt = 0;
    int r = m + 1;
    for (int i = l; i <= m; i++)
    {
        while (r <= h && nums[i] > 2 * nums[r]){
            r++;
        }
        cnt += r - (m + 1);
    }
    return cnt;
}

int CountPair(vector<int> nums, int l, int h)
{
    int res = 0;
    if (l >= h)
        return res;
    int m = l + (h - l) / 2;
    res += CountPair(nums, l, m);
    res += CountPair(nums, m + 1, h);
    res += Pairs(nums, l, m, h);
    Merge(nums, l, m, h);
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
    cout<<CountPair(nums, 0, n - 1);
}