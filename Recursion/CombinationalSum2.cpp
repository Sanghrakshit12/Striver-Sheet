#include <bits/stdc++.h>
using namespace std;
// Brute Force
void fn(vector<int> &nums, int idx, int target, vector<int> &x, set<vector<int>> &res)
{
    if (target == 0)
    {
        sort(x.begin(), x.end());
        res.insert(x);
        return;
    }
    if (idx == nums.size())
        return;
    if (target - nums[idx] >= 0)
    {
        x.push_back(nums[idx]);
        fn(nums, idx + 1, target - nums[idx], x, res);
        x.pop_back();
    }
    fn(nums, idx + 1, target, x, res);
}

vector<vector<int>> CombinationalSum(vector<int> &nums, int target)
{
    vector<int> x;
    set<vector<int>> res;
    fn(nums, 0, target, x, res);
    vector<vector<int>> ans;
    for (const auto &comb : res){
        vector<int> v;
        for (int num : comb)
            v.push_back(num);
        ans.push_back(v);
    }
    return ans;
}

int main()
{
    cout << "Enter size" << endl;
    int n, k;
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
    cout << "enter Target" << endl;
    cin >> k;
    vector<int> x;
    vector<vector<int>> res = CombinationalSum(nums, k);
    for (const auto &comb : res)
    {
        for (int num : comb)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}