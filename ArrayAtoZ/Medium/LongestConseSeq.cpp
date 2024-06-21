#include<bits/stdc++.h>
using namespace std;

//  int Brute(vector<int>nums){
//    int n = nums.size();
//         if (n == 0)
//             return 0;
//         sort(nums.begin(), nums.end());
//         int res = 1, c = 1;
//         for (int i = 0; i < n - 1; i++) {
//             if (nums[i] == nums[i + 1])
//                 continue;
//             if (nums[i + 1] - nums[i] == 1) {
//                 c++;
//                 res = max(res, c);
//             } else
//                 c = 1;
//         }
//         return res;
// }


// O(2n) O(n)
int Longest(vector<int>nums){
    int n=nums.size();
    unordered_set<int>s(nums.begin(),nums.end());
    int res=1;
    if(n==0) return 0;
    for(auto i:s){
        if(s.find(i-1)==s.end()){
            int c=1;
            int x=i+1;
            while(s.find(x)!=s.end()){
                c++;
                x=x+1;
            }
            res=max(res,c);
        }
    }
    return res;
}

int main(){
    vector<int>nums={5,4,4,1,3,2};
    cout<<Longest(nums);
}