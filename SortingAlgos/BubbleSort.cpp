#include <bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++){
        bool b = 0;
        for (int j = 0; j < n - i - 1; j++){
            if (nums[j] > nums[j + 1]){
                swap(nums[j], nums[j + 1]);
                b = 1;
            }
        }
        if (b == 0)
            return;
    }
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
    BubbleSort(nums);
    cout << "Final Matrix" << endl;
    for (auto i : nums)
        cout << i << " ";
}