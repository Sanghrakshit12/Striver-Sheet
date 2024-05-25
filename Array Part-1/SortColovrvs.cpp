#include <bits/stdc++.h>
using namespace std;

// Brute Force
// void Brute_Force(vector<int> &v){
//     sort(v.begin(), v.end());
// }

// Better Approach
// void Better_App(vector<int> &v){
//     int z = 0, o = 0, t = 0;
//     for (int i = 0; i < v.size(); i++){
//         if (v[i] == 0)
//             z++;
//         else if (v[i] == 1)
//             o++;
//         else
//             t++;
//     }
//     int c=0;
//     for (int i = 0; i < z; i++){
//        v[c]=0;
//        c++;
//     }
//      for (int i = 0; i < o; i++){
//        v[c]=1;
//            c++;
//        }
//      for (int i = 0; i < t; i++){
//        v[c]=2;
//            c++;
//     }
// }

void Optimal_App(vector<int> &nums)
{
    int n = nums.size();
    int l = 0, m = 0, h = n - 1;
    while (m <= h)
    {
        if (nums[m] == 0)
        {
            swap(nums[l], nums[m]);
            l++;
            m++;
        }
        else if (nums[m] == 1)
        {
            m++;
        }
        else
        {
            swap(nums[m], nums[h]);
            h--;
        }
    }
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
}

int main()
{
    vector<int> v;
    cout << "Enter Size of Vector" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    Optimal_App(v);
}
