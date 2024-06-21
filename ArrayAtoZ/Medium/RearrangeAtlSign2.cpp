// There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.
//  The leftover elements should be placed at the very end in the same order as in array A.

#include <bits/stdc++.h>
using namespace std;

vector<int> Rearrange(vector<int> nums){
    int n = nums.size();
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++){
        if (nums[i] > 0)
            pos.push_back(nums[i]);
        else
            neg.push_back(nums[i]);
    }
    int p = 0, m = 0;
    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            if (p < pos.size())
                nums[i] = pos[p++];
            else
                nums[i] = neg[m++];
        }
        else{
            if (m < neg.size())
                nums[i] = neg[m++];
            else
                nums[i] = pos[p++];
        }
    }
    return nums;
}
int main(){
    vector<int> nums = {1, 2, -4, -5, 3, 4};
    vector<int> res = Rearrange(nums);
    for (auto i : res)
        cout << i << " ";
}