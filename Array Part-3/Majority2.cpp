#include <bits/stdc++.h>
using namespace std;

// vector<int> Brute(vector<int> nums)
// {
//     vector<int> res;
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (res.empty() || res[0] != nums[i])
//         {
//             int c = 0;
//             for (int j = 0; j < n; j++)
//             {
//                 if (nums[i] == nums[j])
//                     c++;
//             }
//             if (c > (n / 3))
//                 res.push_back(nums[i]);
//         }
//         if (res.size() == 2)
//             return res;
//     }
//     return res;
// }

// vector<int> Better(vector<int> nums)
// {
//     vector<int> res;
//     int n = nums.size();
//     int min = (n / 3) + 1;
//     map<int, int> mpp;
//     for (int i = 0; i < n; i++)
//     {
//         mpp[nums[i]]++;
//         if (mpp[nums[i]] == min)
//         {
//             res.push_back(nums[i]);
//         }
//         if (res.size() == 2)
//         {
//             return res;
//         }
//     }
//     return res;
// }

vector<int> majorityElement(vector<int> &nums){
    vector<int> res;
    int n = nums.size();
    int c1 = 0, c2 = 0;
    int x = INT_MIN, y = INT_MIN;
    for (int i = 0; i < n; i++){
        if (c1 == 0 && nums[i] != y){
            x = nums[i];
            c1++;
        }
        else if (c2 == 0 && nums[i] != x){
            y = nums[i];
            c2++;
        }

        else if (nums[i] == x)
            c1++;
        else if (nums[i] == y)
            c2++;
        else{
            c1--;
            c2--;
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++){
        if (nums[i] == x)
            cnt1++;
        if (nums[i] == y)
            cnt2++;
    }
    if (cnt1 > (n / 3))
        res.push_back(x);
    if (cnt2 > (n / 3))
        res.push_back(y);
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
    vector<int> res = majorityElement(nums);
    for (auto i : res)
    {
        cout << i << " ";
    }
}