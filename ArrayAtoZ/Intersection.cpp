#include <bits/stdc++.h>
using namespace std;

// vector<int> Brute(vector<int> nums1, vector<int> nums2){
//     vector<int>ans;
//     int n = nums1.size();
//     int m = nums2.size();
//     vector<int> res(m, -1);
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++){
//             if(nums1[i]==nums2[j] && res[j]==-1){
//                 ans.push_back(nums1[i]);
//                 res[j]=0;
//                 break;
//             }
//             if(nums2[j]>nums1[i]) break;
//         }
//     }
//     return ans;
// }

vector<int> printIntersection(vector<int> nums1, vector<int> nums2){
    int n = nums1.size();
    int m = nums2.size();
    vector<int> res;
    int i = 0, j = 0;
    while (i < n && j < m){
        if (nums1[i] < nums2[j])
            i++;
        else if (nums2[j] > nums1[i])
            j++;
        else{
            res.push_back(nums1[i]);

            i++;
            j++;
        }
    }
    if (res.empty())
        return vector<int>{-1};
    else
        return res;
}

int main(){
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {2, 2, 3, 4, 5};
    // vector<int> v3 = Brute(v1, v2);
    // for (auto i : v3)
    //     cout << i << " ";
    vector<int> v3 = printIntersection(v1, v2);
    for (auto i : v3)
        cout << i << " ";
}