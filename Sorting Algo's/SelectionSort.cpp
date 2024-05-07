#include <bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int temp=i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[temp])
                temp=j;
        }
        if(temp!=i) swap(nums[i],nums[temp]);
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
    SelectionSort(nums);
    cout << "Final Matrix" << endl;
    for (auto i : nums)
        cout << i << " ";
}