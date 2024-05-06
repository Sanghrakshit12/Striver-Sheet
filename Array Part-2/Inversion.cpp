#include <bits/stdc++.h>
using namespace std;

int Brute(vector<int> &nums)
{
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (nums[j] < nums[i])
                res++;
        }
    }
    return res;
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
    cout<<Brute(nums);
}