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

vector<int> Better(vector<int> &nums){
    int r = -1, m = -1;
    int hash[nums.size()] = {0};
    for (int i = 0; i < nums.size(); i++){
        hash[nums[i] - 1]++;
    }
    for (int i = 0; i < nums.size(); i++){
        if (hash[i] == 2)
            r = i + 1;
        if (hash[i] == 0)
            m = i + 1;
    }
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
    vector<int> res = Better(nums);
    for (auto i : res)
    {
        cout << i << " ";
    }
}