#include <bits/stdc++.h>
using namespace std;

int firstOccour(vector<int> nums, int x){
    int n = nums.size();
    int l = 0, h = n - 1, res = -1;
    while (l <= h){
        int m = l + (h - l) / 2;
        if (nums[m] == x){
            res = m;
            h = m - 1;
        }
        else if (nums[m] > x)
            h = m - 1;
        else
            l = m + 1;
    }
    return res;
}

int LastOccour(vector<int> nums, int x){
    int n = nums.size();
    int l = 0, h = n - 1, res = -1;
    while (l <= h){
        int m = l + (h - l) / 2;
        if (nums[m] == x){
            res = m;
            l = m + 1;
        }
        else if (nums[m] > x)
            h = m - 1;
        else
            l = m + 1;
    }
    return res;
}

int CountOccourence(vector<int> nums, int x){
    if (LastOccour(nums, x) == -1 || firstOccour(nums, x) == -1)
        return 0;
    return LastOccour(nums, x) - firstOccour(nums, x) + 1;
}
int main()
{
    cout << "Enter size" << endl;
    int n;
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
    int target;
    cout << "Enter Target" << endl;
    cin >> target;
    int x = CountOccourence(nums, target);
    cout << x;
}