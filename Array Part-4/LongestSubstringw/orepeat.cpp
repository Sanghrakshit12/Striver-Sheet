#include<bits/stdc++.h>
using namespace std;

int Brute(vector<char>nums){
    unordered_map<char,int>mpp;
    int n=nums.size();
    int res=1;
    for(int i=0;i<n;i++){
        if(mpp.find(nums[i])!=mpp.end()){
            res=max(res,i-mpp[nums[i]]);
        }
        mpp[nums[i]]=i;
    }
}

int main(){
cout << "Enter size" << endl;
    int n;
    cin >> n;
    vector<char> nums;
    for (int i = 0; i < n; i++)
    {
        char a;
        cin >> a;
        nums.push_back(a);
    }
    cout << "initial Matrix" << endl;
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
}