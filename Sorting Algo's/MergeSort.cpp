#include <bits/stdc++.h>
using namespace std;

// Time Complexity -> O(nlogn)
// Space Complexity -> O(n)

void Merge(vector<int> &nums, int l, int m, int h){
    int i = l, j = m + 1;
    vector<int> temp;

    while (i <= m && j <= h)
    {
        if (nums[i] <= nums[j]) 
            temp.push_back(nums[i++]);
        else
            temp.push_back(nums[j++]);
    }
    while (i <= m)
        temp.push_back(nums[i++]);
    while (j <= h)
        temp.push_back(nums[j++]);
    for (int k = l; k <= h; k++)
        nums[k] = temp[k - l];
}

void MergeSort(vector<int> &nums, int l, int h){
    if (l >= h)
        return;
    int m = l + (h - l) / 2;
    MergeSort(nums, l, m);
    MergeSort(nums, m + 1, h);
    Merge(nums, l, m, h);
}

int main(){
    cout << "Enter size" << endl;
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << "initial Matrix" << endl;
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
    MergeSort(nums, 0, n - 1);
     cout << "Final Matrix" << endl;
    for (auto i : nums)
        cout << i << " ";
}