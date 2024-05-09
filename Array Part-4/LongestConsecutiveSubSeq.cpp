#include <bits/stdc++.h>
using namespace std;

// bool Linear(vector<int> nums, int x)
// {
//     int n = nums.size();
//     for (int j = 0; j < n; j++)
//     {
//         if (nums[j] == x)
//             return 1;
//     }
//     return 0;
// }
// int Brute(vector<int> &nums)
// {
//     int n = nums.size();
//     int res = 1;
//     if (n == 0)
//         return 0;

//     for (int i = 0; i < n; i++)
//     {
//         int num = nums[i] + 1;
//         int c = 1;
//         while (Linear(nums, num))
//         {
//             num += 1;
//             c++;
//         }
//         res = max(res, c);
//     }
// }

// int Better(vector<int> &nums){
//     int n = nums.size();
//     if (n == 0)
//         return 0;
//     sort(nums.begin(), nums.end());
//     int c = 1, res = 1;
//     for (int i = 1; i < n; i++){
//         if (nums[i] == nums[i - 1])
//             continue;
//         if (nums[i] - nums[i - 1] == 1)
//             c++;
//         else
//             c = 1;
//         res = max(res, c);
//     }
//     return res;
// }

int Optimal(vector<int> &nums){
    int n = nums.size();
    if (n == 0)
        return 0;
    unordered_set<int> s;
    for (auto i : nums)
        s.insert(i);
    int res = 1;
    for (int i : s){
        int c = 1;
        if (s.find(i - 1) != s.end())
            continue;
        int x = i + 1;
        while (s.find(x) != s.end()){
            x++;
            c++;
        }
        res = max(res, c);
    }
    return res;
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
    cout << Optimal(nums);
}
