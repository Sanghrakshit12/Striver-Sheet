#include <bits/stdc++.h>
using namespace std;

// int Brute(vector<int> nums){
//     int n = nums.size();
//     for (int i = 0; i < n; i++){
//         int c = 0;
//         for (int j = 0; j < n; j++){
//             if (nums[i] == nums[j])
//                 c++;
//         }
//         if (c > (n / 2))
//             return nums[i];
//     }
// }

// int Better(vector<int> nums){
//     int n = nums.size();
//     map<int, int> mpp;
//     for (int i = 0; i < n; i++)
//         mpp[nums[i]]++;
//     for (auto i : mpp){
//         if (i.second > (n / 2))
//             return i.first;
//     }
// }

int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int c = 0, x;
    for (int i = 0; i < n; i++)
    {
        if (c == 0)
            x = nums[i];
        if (x == nums[i])
            c++;
        else
            c--;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == x)
            cnt++;
    }
    if (cnt > (n / 2))
        return x;
    else
        return -1;
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
    cout << majorityElement(nums);
}