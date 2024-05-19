// You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
// The floor of x is the largest element in the array which is smaller than or equal to x.
// The ceiling of x is the smallest element in the array greater than or equal to x.

#include <bits/stdc++.h>
using namespace std;

int Ceil(vector<int> nums, int x){
    int n = nums.size();
    int l = 0, h = n - 1, res = n;
    while (l <= h){
        int m = l + (h - l) / 2;
        if (nums[m] >= x){
            res = nums[m];
            h = m - 1;
        }
        else
            l = m + 1;
    }
    return res;
}

int Floor(vector<int> nums, int x){
    int n = nums.size();
    int l = 0, h = n - 1, res = n;
    while (l <= h){
        int m = l + (h - l) / 2;
        if (nums[m] <= x){
            res = nums[m];
            l = m + 1;
        }
        else
            h = m - 1;
    }
    return res;
}

vector<int> FloornCeil(vector<int> nums, int x){
    int n = nums.size();
    int l = 0, h = n - 1;
    int c = Ceil(nums, x);
    int f = Floor(nums, x);
    return {f, c};
}

int main(){
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
    int target;
    cout << "Enter Value" << endl;
    cin >> target;
    vector<int> x = FloornCeil(nums, target);
    for (auto i : x)
    {
        cout << i << " ";
    }
}