#include <bits/stdc++.h>
using namespace std;

int Optimal(vector<int> nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> mpp;
    int s = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        s += nums[i];
        if (s == k || mpp.find(s - k) != mpp.end())
            c++;
        mpp[s] = i;
    }
    return c;
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
    cout << "Enter Target" << endl;
    int k;
    cin >> k;
    cout << Optimal(nums, k);
}