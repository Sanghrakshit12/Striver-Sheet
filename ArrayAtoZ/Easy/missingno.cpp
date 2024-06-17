// Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

#include <bits/stdc++.h>
using namespace std;

// Using XOR
int missingNumber(vector<int> &nums){
    int n = nums.size();
    int s = 1;
    for (int i = 1; i <= n; i++)
        s ^= i;
    int x = 1;
    for (int i = 0; i < n; i++)
        x ^= nums[i];
    return x ^ s;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n - 1; i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int sum = n * (n + 1) / 2;
    int s = 0;
    for (int i = 0; i < n - 1; i++)
        s += nums[i];
    cout << sum - s;
}