#include <bits/stdc++.h>
using namespace std;

void Rotate(vector<int> &nums){
    int n = nums.size();
    int x = nums[0];
    for (int i = 0; i < n - 1; i++)
        nums[i] = nums[i + 1];
    nums[n - 1] = x;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    Rotate(nums);
    for (auto i : nums)
        cout << i << " ";
}