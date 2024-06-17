#include <bits/stdc++.h>
using namespace std;

// Using Extra Space  O(n) O(n)
void rotate(vector<int> &nums, int k)
{
    vector<int> x;
    int n = nums.size();
    k = k % n;
    if (k == 0)
        return;
    for (int i = n - k; i < n; i++)
        x.push_back(nums[i]);
    for (int i = 0; i < n - k; i++)
        x.push_back(nums[i]);
    int c = 0;
    for (auto i : x){
        nums[c] = i;
        c++;
    }
}

// O(n) O(1)
void OptimalRotate(vector<int> &nums, int k){
    int n=nums.size();
    k=k%n;
    if(k==0) return;
    reverse(nums.begin(),nums.begin()+n-k);
    reverse(nums.begin()+n-k,nums.end());
    reverse(nums.begin(),nums.end());
}

int main(){
    int k;
    cin >> k;
    vector<int> nums = {1, 2, 3, 4, 5};
    // rotate(nums, k);
    // for (auto i : nums)
    //     cout << i << " ";
    // cout<<endl;
    OptimalRotate(nums, k);
    for (auto i : nums)
        cout << i << " ";
}