#include <bits/stdc++.h>
using namespace std;

// TC - O(n)+O(n)  SC-O(n)
// void Brute(vector<int> &nums){
//     int n = nums.size();
//     vector<int> posi;
//     vector<int> neg;
//     for (int i = 0; i < n; i++){
//         if (nums[i] > 0)
//             posi.push_back(nums[i]);
//         else
//             neg.push_back(nums[i]);
//     }
//     int c = 0, d = 0;
//     for (int i = 0; i < n; i++){
//         if (i % 2 == 0)
//             nums[i] = posi[c++];
//         else
//             nums[i] = neg[d++];
//     }
// }


// TC - O(n)  SC-O(n)
vector<int> rearrangeArray(vector<int> &nums){
    int n = nums.size();
    vector<int> res(n, 0);
    int pos = 0, neg = 1;
    for (int i = 0; i < n; i++){
        if (nums[i] > 0){
            res[pos] = nums[i];
            pos += 2;
        }
        else{
            res[neg] = nums[i];
            neg += 2;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
    vector<int> res = (nums);
    for (auto i : res)
        cout << i << " ";
}