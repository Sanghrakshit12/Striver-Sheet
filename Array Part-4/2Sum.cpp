#include <bits/stdc++.h>
using namespace std;

// vector<int> Brute(vector<int> nums, int target){
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (nums[i] + nums[j] == target)
//             {
//                 return {i, j};
//             }
//         }
//     }
//     return {-1, -1};
// }

// if we want to return the indexes the hashing approach is Optimal

vector<int> Better(vector<int> nums, int target){
    unordered_map<int, int> mpp;
    int n = nums.size();
    for (int i = 0; i < n; i++){
        int num = target - nums[i];
        if (mpp.find(num) != mpp.end())
            return {mpp[num], i};
        mpp[nums[i]] = i;
    }
    return {-1,-1};
}

// if we want to return yes or no then this approach is Optimal

int Optimal(vector<int> nums, int target){
    int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        while(i<j){
            if(nums[i]+nums[j]>target){
                j--;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{
                return 1;
            }
        }
        return 0;
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
    cout << "Enter Target" << endl;
    int s;
    cin >> s;
    // vector<int> res = Better(nums, s);
    // for (auto i : res)
    // {
    //     cout << i << " ";
    // }
}
