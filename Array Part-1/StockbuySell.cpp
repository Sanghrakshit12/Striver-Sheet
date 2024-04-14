#include<bits/stdc++.h>
using namespace std;

// Brute_Force
// int Brute_Force(vector<int> &arr) {
//     int maxPro = 0;
//     int n = arr.size();

//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j] > arr[i]) {
//             maxPro = max(arr[j] - arr[i], maxPro);
//             }
//         }
//         }

//     return maxPro;
// }

// Optimal Approach
int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int b=0,res=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[b])
                b=i;
            else
               res= max(nums[i]-nums[b],res);
        }
        return res;
    }

int main()
{
    vector<int> v;
    cout << "Enter Size of Vector" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout<<maxProfit(v);  
}
