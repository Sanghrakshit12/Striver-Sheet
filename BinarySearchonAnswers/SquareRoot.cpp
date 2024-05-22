// You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

#include <bits/stdc++.h>
using namespace std;

// long long int Brute(long long int x){
//     long long ans = 0;
//     for (long long i = 1; i <= x; i++){
//         long long val = i * i;
//         if (val <= x)
//             ans = i;
//         else
//             break;
//     }
//     return ans;
// }

long long int sqrt(long long int x){
    if(x==1) return 1;
    int l = 1, h = x / 2;
    while (l <= h){
        long long m = l + (h - l) / 2;
        if (m * m <= x)
            l = m + 1;
        else
            h = m - 1;
    }
    return h;
}

int main(){
    cout << "Enter The Number" << endl;
    long long int n;
    cin >> n;
    // cout << Brute(n);
    cout<<sqrt(n);
}