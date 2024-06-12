#include<bits/stdc++.h>
using namespace std;

// TC-O(2^n*n) SC-O(n)
void Subsequence(vector<int>nums,int idx,vector<int>&res){
    if(idx>=nums.size()){
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
        return;
    }
    res.push_back(nums[idx]);
    Subsequence(nums,idx+1,res);
    res.pop_back();
    Subsequence(nums,idx+1,res);
}

int main(){
    vector<int>nums;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
     vector<int>x;
    Subsequence(nums,0,x);
}