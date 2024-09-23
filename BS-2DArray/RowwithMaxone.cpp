#include <bits/stdc++.h>
using namespace std;

int Brute(vector<vector<int>>nums){
    int n=nums.size();
    int res=-1,x=0;
    int m=nums[0].size();
    for(int i=0;i<n;i++){
        int c=0;
        for(int j=0;j<m;j++){
            if(nums[i][j]==1)
                c++;
        }
        if(c>x){
            res=i;
            x=c;  
        }
    }
    return res;
}

// Optimal

int fn(vector<vector<int>>nums){
    int 
}

int Optimal(vector<vector<int>>nums){
    int n=nums.size();
    int m=nums[0].size();
    for(int i=0;i<n;i++){
        
    }
}

int main()
{
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nums[i][j];
        }
    }
    if(Brute(nums)==-1) cout<<"-1"<<endl;
    else cout<<Brute(nums);
}
