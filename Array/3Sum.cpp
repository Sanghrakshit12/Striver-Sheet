#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N^3 * log(no. of unique triplets)),Space Complexity: O(2 * no. of the unique triplets)

// vector<vector<int>> Brute(vector<int> nums){
//     int n = nums.size();
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++){
//         for (int j = i + 1; j < n; j++){
//             for (int k = j + 1; k < n; k++){
//                 if (nums[i] + nums[j] + nums[k] == 0){
//                     vector<int> temp = {nums[i], nums[j], nums[k]};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

// vector<vector<int>> Better(vector<int> nums)
// {
//     set<vector<int>> st;
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         set<int> hashset;
//         for (int j = i + 1; j < n; j++)
//         {
//             int x = 0 - (nums[i] + nums[j]);
//             if (hashset.find(x) != hashset.end())
//             {
//                 vector<int> temp = {nums[i], nums[j], x};
//                 sort(temp.begin(), temp.end());
//                 st.insert(temp);
//             }
//             hashset.insert(nums[j]);
//         }
//     }
//     vector<vector<int>> res(st.begin(), st.end());
//     return res;
// }

vector<vector<int>> Optimal(vector<int> &nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0)
            {
                res.push_back({nums[i], nums[j], nums[k]});
                while (j < k && nums[j] == nums[j + 1])
                    j++;
                while (j < k && nums[k] == nums[k - 1])
                    k--;
                j++;
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
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
    vector<vector<int>> res = Optimal(nums);
    for (auto it : res)
    {
        cout << "[";
        for (auto i : it)
            cout << i << " ";
        cout << "]";
    }
}