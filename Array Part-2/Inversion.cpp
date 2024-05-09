#include <bits/stdc++.h>
using namespace std;

// int Brute(vector<int> &nums)
// {
//     int n = nums.size();
//     int res = 0;
//     for (int i = 0; i < n; i++){
//         for (int j = i + 1; j < n; j++){
//             if (nums[j] < nums[i])
//                 res++;
//         }
//     }
//     return res;
// }

int Merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    int cnt = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return cnt;
}

int Optimal(vector<int> &nums, int l, int h)
{
    int res = 0;
    if (l >= h)
        return res;
    int m = l + (h - l) / 2;
    res += Optimal(nums, l, m);
    res += Optimal(nums, m + 1, h);
    res += Merge(nums, l, m, h);
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
        cout << i << " ";
    cout << endl;
    cout << Optimal(nums, 0, n - 1);
}