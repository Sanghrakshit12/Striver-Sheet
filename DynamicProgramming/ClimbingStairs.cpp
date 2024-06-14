#include <bits/stdc++.h>
using namespace std;

/* int fn1(int n, vector<int>& dp) {
  if(n==0) return 1;
  if(n==1) return 1;
  if(dp[n]!=-1) return dp[n];
  return dp[n]=fn(n-1,dp)+fn(n-2,dp);
} */

/* int fn2(int n, vector<int>& dp) {
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
} */

int climbStairs(int n){
    int x = 1, y = 1;
    for (int i = 2; i <= n; i++)
    {
        int c = x + y;
        x = y;
        y = c;
    }
    return y;
    // vector<int> dp(n + 1, -1);
    // return fn(n, dp);
}


int main(){
    int n=2;
    cout<<climbStairs(n);
}