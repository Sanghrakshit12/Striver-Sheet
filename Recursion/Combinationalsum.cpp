#include <bits/stdc++.h>
using namespace std;

void fn(vector<int> &nums, int idx, int target, vector<int> &x, vector<vector<int>> &res){
    if (target == 0){
        res.push_back(x);
        return;
    }
    if (idx == nums.size())
        return;
    if (target - nums[idx] >= 0){
        x.push_back(nums[idx]);
        fn(nums, idx, target - nums[idx], x, res);
        x.pop_back();
    }
        fn(nums, idx + 1, target, x, res);
}

vector<vector<int>> CombinationalSum(vector<int> &nums, int target){
    vector<int> x;
    vector<vector<int>> res;
    fn(nums, 0, target, x, res);
    return res;
}

int main(){
    cout << "Enter size" << endl;
    int n, k;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++){ 
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
    for (const auto &comb : res){
        for (int num : comb)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}