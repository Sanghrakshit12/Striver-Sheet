#include<bits/stdc++.h>
using namespace std;
 

// Memoization Tc-O(n) SC-O(n)+O(n)
int fibo1(int n,vector<int>&dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fibo1(n-1,dp)+fibo1(n-2,dp);
}

// Tabulation Tc-O(n) SC-O(n)
void fibo2(int n,vector<int>&dp){
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;
}

// Optimizing Space Tc-O(n) SC-O(1)
void fibo3(int n)
{
    int x=0;
    int y=1;
    for(int i=2;i<=n;i++){
        int c=x+y;
        x=y;
        y=c;
    }
    cout<<y<<endl;
}


int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<fibo1(n,dp)<<endl;
    fibo2(n,dp);
    fibo3(n);
}