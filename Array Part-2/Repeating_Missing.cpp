#include <bits/stdc++.h>
using namespace std;

// vector<int> Brute(vector<int> nums)
// {
//     int n = nums.size();
//     int r=-1,m=-1;
//     for (int i = 1; i <=n; i++){
//         int c = 0;
//         for (int j = 0; j < n; j++){
//             if (i == nums[j])
//                 c++;
//         }
//         if (c == 2)
//              r = i;
//         if (c == 0)
//              m = i;
//     }
//     return {r,m};
// }

// vector<int> Better(vector<int> &nums){
//     int r = -1, m = -1;
//     int hash[nums.size()] = {0};
//     for (int i = 0; i < nums.size(); i++){
//         hash[nums[i] - 1]++;
//     }
//     for (int i = 0; i < nums.size(); i++){
//         if (hash[i] == 2)
//             r = i + 1;
//         if (hash[i] == 0)
//             m = i + 1;
//     }
//     return {r, m};
// }

vector<int> Optimal(vector<int> &nums)
{
    int n = nums.size();
    int sn = n * (n + 1) / 2;
    int s = 0, s2 = 0;
    int sn2 = (n * (n + 1) * (2 * n + 1)) / 6;
    for (int i = 0; i < n; i++)
    {
        s += nums[i];
        s2 += nums[i] * nums[i];
    }
    int x = sn - s;
    int y = sn2 - s2;
    y /= x;
    int m = (x + y) / 2;
    int r = m - x;
    return {r, m};
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
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> res = Optimal(nums);
    for (auto i : res)
    {
        cout << i << " ";
    }
}