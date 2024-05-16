#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N^4), where N = size of the array. Space Complexity: O(2 * no. of the quadruplets) as we are using a set data structure and a list to store the quads.
// vector<vector<int>> Brute(vector<int> nums, int target){
//     set<vector<int>> st;
//     int n = nums.size();
//     for (int i = 0; i < n; i++){
//         for (int j = i + 1; j < n; j++){
//             for (int k = j + 1; k < n; k++){
//                 for (int p = k + 1; p < n; p++){
//                     long long sum = nums[i] + nums[j] + nums[k] + nums[p];
//                     if (sum == target){
//                         vector<int> temp = {nums[i], nums[j], nums[k], nums[p]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>> res(st.begin(), st.end());
//     return res;
// }

// Time Complexity : O(N^3 *log(M)), where N = size of the array, M = no.of elements in the set.Space Complexity : O(2 * no.of the quadruplets) + O(N) vector<vector<int>> Better(vector<int> nums, int target){
//     int n = nums.size();
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++){
//         for (int j = i + 1; j < n; j++){
//             set<int> hashset;
//             for (int k = j + 1; k < n; k++){
//                 int val = target - (nums[i] + nums[j] + nums[k]);
//                 if (hashset.find(val) != hashset.end()){
//                     vector<int> temp = {nums[i], nums[j], nums[k], val};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(nums[k]);
//             }
//         }
//     }
//     vector<vector<int>> res(st.begin(), st.end());
//     return res;
// }

// Time Complexity: O(N^3), where N = size of the array.Space Complexity: O(1)
vector<vector<int>> Optimal(vector<int> nums, int target){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < n; i++){
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++){
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int k = j + 1, p = n - 1;
            while (k < p){
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target)
                {
                    res.push_back({nums[i], nums[j], nums[k], nums[p]});
                    while (k < p && nums[k] == nums[k + 1])
                        k++;
                    while (k < p && nums[p] == nums[p - 1])
                        p--;
                    k++;
                    p--;
                }
                else if (sum < target)
                    k++;
                else
                    p--;
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
    int target;
    cout << "Enter Target" << endl;
    cin >> target;
    vector<vector<int>> res = Optimal(nums, target);
    for (auto it : res)
    {
        cout << "[";
        for (auto i : it)
            cout << i << " ";
        cout << "]";
    }
}