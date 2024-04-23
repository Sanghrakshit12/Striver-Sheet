#include <bits/stdc++.h>
using namespace std;

// Brute Force
// void MergeSortedArray(vector<int> &v1, vector<int> &v2){
//     int n = v1.size();
//     int m = v2.size();
//     vector<int> res;
//     int i = 0, j = 0;
//     while (i < n && j < m){
//         if (v1[i] <= v2[j]){
//             res.push_back(v1[i]);
//             i++;
//         }
//         else{
//             res.push_back(v2[j]);
//             j++;
//         }
//     }
//     while (i < n){
//         res.push_back(v1[i]);
//         i++;
//     }
//     while (j < m){
//         res.push_back(v2[j]);
//         j++;
//     }
//     cout << "Merged Array " << endl;
//     for (auto k : res)
//         cout << k << " ";
// }

// Optimal Approach 1
void MergeSortedArray(vector<int> &v1, vector<int> &v2){
    int n = v1.size();
    int m = v2.size();
    int l = n - 1;
    int r = 0;
    while (l >= 0 && r < m){
        if (v1[l] > v2[r]){
            swap(v1[l], v2[r]);
            l--;
            r++;
        }
        else
           break;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
}



int main()
{
    vector<int> v1;
    vector<int> v2;
    cout << "Enter Size of Vectors" << endl;
    int n, m;
    cin >> n >> m;
    cout << "Enter first Vector" << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    cout << "Enter Second Vector" << endl;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v2.push_back(x);
    }
    MergeSortedArray(v1, v2);
    for (auto k : v1)
        cout << k << " ";
    cout<<endl;
    for (auto k : v2)
        cout << k << " ";
}