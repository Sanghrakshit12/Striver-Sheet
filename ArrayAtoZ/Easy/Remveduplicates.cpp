#include <bits/stdc++.h>
using namespace std;

// Using Extra space O(n) O(n)+O(nlogn)
vector<int> removeDuplicates2(vector<int> &nums){
    int n = nums.size();
    set<int> s;
    for (auto i : nums)
        s.insert(i);
    int c = 0;
    for (auto i : s){
        nums[c] = i;
        c++;
    }
    cout << s.size() << endl;
    return nums;
}

// Inplace O(n) O(1)
int removeDuplicates(vector<int> &nums){
    int n = nums.size();
    int c = 0;
    for (int i = 1; i < n; i++){
        if (nums[i] != nums[c]){
            nums[c + 1] = nums[i];
            c++;
        }
    }
    return c + 1;
}

int main(){
    vector<int> v = {1, 1, 2};
    cout << removeDuplicates(v) << endl;
    vector<int> nums = removeDuplicates2(v);
    for (auto i : nums)
        cout << i << " ";
}