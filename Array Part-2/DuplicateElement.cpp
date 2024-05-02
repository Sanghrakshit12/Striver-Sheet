#include <bits/stdc++.h>
using namespace std;

// int Brute(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     for (int i = 0; i < nums.size()-1; i++)
//     {
//         if (nums[i]==nums[i+1]){
//             return nums[i];
//         }
//     }
//     return -1;
// }

// int Better(vector<int>&nums){
//     int n=nums.size();
//     vector<int>res(n+1,0);
//     for(int i=0;i<n;i++){
//         if(res[nums[i]]==0)
//         res[nums[i]]++;
//         else{
//             return nums[i];
//         }
//     }
//     return -1;
// }

int Optimal(vector<int> &nums)
{
    int n = nums.size();
    int s = nums[0], f = nums[0];
    do
    {
        s=nums[s];
        f=nums[nums[f]];
    } while (s != f);
    f=nums[0];
    while (s!=f)
    {
          s=nums[s];
          f=nums[f];
    }
    return s;
    

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
    cout << Optimal(nums);
}