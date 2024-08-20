#include <bits/stdc++.h>
using namespace std;

int Brute(vector<int>nums){
    int n=nums.size();
    int res=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int p=1;
            for(int k=i;k<=j;k++)
                p*=nums[k];
            res=max(res,p);
        }
    }
    return res;
}

int Better(vector<int>nums){
    int n=nums.size();
    int res=INT_MIN;
    for(int i=0;i<n;i++){
        int p=1;
        for(int j=i;j<n;j++){
            p*=nums[j];
            res=max(res,p);
        }
    }
    return res;
}

int main(){
    cout << "Enter size" << endl;
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout<<Brute(nums)<<endl;
    cout<<Better(nums)<<endl;
}