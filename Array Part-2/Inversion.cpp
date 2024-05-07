#include <bits/stdc++.h>
using namespace std;

// int Brute(vector<int> &nums)
// {
//     int n = nums.size();
//     int res = 0;
//     for (int i = 0; i < n; i++){
//         for (int j = i + 1; j < n; j++){
//             if (nums[j] < nums[i])
//                 res++;
//         }
//     }
//     return res;
// }

int Merge(vector<int> &nums, int l, int m, int h)
{
    int i = l;
    int j = m + 1;
    vector<int> temp;
    int c = 0;
    while (i <= m && j <= h)
    {
        if (nums[i] <= nums[j])
            temp.push_back(nums[i++]);
        else
        {
            c += m - l + 1;
            temp.push_back(nums[j++]);
        }
    }
    while (i <= m)
        temp.push_back(nums[i++]);
    while (j <= h)
        temp.push_back(nums[j++]);
    return c;
}

int Optimal(vector<int> &nums, int l, int h){
    int res = 0;
    if (l >= h)
        return res;
    int m = l + (h - l) / 2;
    res += Optimal(nums, l, m);
    res += Optimal(nums, m + 1, h);
    res += Merge(nums, l, m, h);
    return res;
}

int main(){
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
    cout << Optimal(nums, 0, n - 1);
}