#include <bits/stdc++.h>
using namespace std;

// int Brute(string s){
//     int n = s.length();
//     if (n == 0)
//         return 0;
//     int res = 1;
//     for (int i = 0; i < n; i++)
//     {
//         unordered_set<char> mpp;
//         mpp.insert(s[i]);
//         for (int j = i + 1; j < n; j++)
//         {
//             if (mpp.find(s[j]) != mpp.end())
//                 break;
//             mpp.insert(s[j]);
//             res = max(res, j - i + 1);
//         }
//     }
//     return res;
// }

int Better(string s){
    int n = s.length();
    if (n == 0)
        return 0;
    int l = 0, r = 0, res = 0;
    unordered_set<char> mpp;
    while (r < n)
    {
        while (mpp.find(s[r]) != mpp.end() && l < r)
        {
            mpp.erase(s[l]);
            l++;
        }
        mpp.insert(s[r]);
        res = max(res, r - l + 1);
        r++;
    }
    return res;
}

int Optimal(string s)
{
    int n = s.length();
    if (n == 0)
        return 0;
    int l = 0, r = 0, res = 0;
    unordered_map<char, int> mpp;
    while (r < n)
    {
        if (mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l)
        {
            l = mpp[s[r]] + 1;
        }
        mpp[s[r]] = r;
        res = max(res, r - l + 1);
        r++;
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << Optimal(s);
}