// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.

#include <bits/stdc++.h>
using namespace std;

// int Brute(vector<int> nums){
//     int n = nums.size();
//     for (int i = 0; i < n; i++){
//         int b = 0;
//         for (int j = 0; j < n; j++){
//             if (nums[i] == nums[j])
//                 b++;
//         }
//         if (b !=2)
//             return nums[i];
//     }
//     return -1;
// }

// int Better(vector<int> nums){
//     int n=nums.size();
//     int c=nums[0];
//     for(int i=1;i<n;i++){
//         c=c^nums[i];
//     }
//     return c;
// }

int Single(vector<int> nums){
    int n = nums.size();
    int l = 0, h = n - 1;
    while (l <= h){
        int m = l + (h - l) / 2;
        if (nums[m] == nums[m + 1]){
            if ((m - l) % 2 == 0)
                l = m ;
            else
                h = m - 1;
        }
        else if (nums[m] == nums[m - 1]){
            if ((h - m) % 2 == 0)
                h = m ;
            else
                l = m + 1;
        }
        else
            return nums[m];
    }
    return -1;
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
    int x = Single(nums);
    cout << x;
}