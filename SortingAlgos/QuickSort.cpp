#include <bits/stdc++.h>
using namespace std;

int quickfn(vector<int> &nums, int l, int h){
    int i = l, j = h;
    int pvt = nums[l];
    while (i < j){
        while (nums[i] <= pvt && i < h)
            i++;
        while (nums[j] > pvt && j > l)
            j--;
        if (i < j)
            swap(nums[i], nums[j]);
    }
    swap(nums[j], nums[l]);
    return j;
}

void QuickSort(vector<int> &nums, int l, int h){
    if (l < h){
        int partition = quickfn(nums, l, h);
        QuickSort(nums, l, partition - 1);
        QuickSort(nums, partition + 1, h);
    }
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
    QuickSort(nums, 0, n - 1);
    cout << "Final Matrix" << endl;
    for (auto i : nums)
        cout << i << " ";
}