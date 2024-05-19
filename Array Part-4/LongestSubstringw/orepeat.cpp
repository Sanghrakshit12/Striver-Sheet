#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n^2) Space Complexity - O(n)
// int Brute(vector<char> st){
//     int n = st.size();
//     int maxi = 0;
//     for (int i = 0; i < n; i++){
//         unordered_set<char> hashset;
//         for (int j = i; j < n; j++){
//             if (hashset.find(st[j]) != hashset.end()){
//                 break;
//             }
//             hashset.insert(st[j]);
//             maxi = max(maxi, j - i + 1);
//         }
//     }
//     return maxi;
// }

// Time Complexity - O(2n) Space Complexity - O(n)
// int OptimalApp_1(vector<char> st){
//     int n = st.size();
//     if (n == 0)
//         return 0;
//     int l = 0, h = 0, maxi = 0;
//     unordered_set<char> s;
//     while (l < n && h < n){
//         if (s.find(st[h]) != s.end()){
//             while (s.find(st[h]) != s.end()){
//                 s.erase(st[l]);
//                 l++;
//             }
//         }
//         s.insert(st[h]);
//         maxi = max(maxi, h - l + 1);
//         h++;
//     }
//     return maxi;
// }

// Time Complexity - O(n) Space Complexity - O(n)
int lengthOfLongestSubstring(vector<char> s)
{
    int n = s.size();
    if (n == 0)
        return 0;
    unordered_map<char, int> mpp;
    int h = 0, l = 0, maxi = 0;
    while (h < n && l < n)
    {
        if (mpp.find(s[h]) != mpp.end())
        {
            l = max(mpp[s[h]] + 1, l);
        }
        mpp[s[h]] = h;
        maxi = max(maxi, h - l + 1);
        h++;
    }
    return maxi;
}

int main()
{
    cout << "Enter Length of String" << endl;
    vector<char> st;
    int n;
    cin >> n;
    cout << "Enter String" << endl;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        st.push_back(c);
    }
    cout << "Orignal String" << endl;
    for (auto i : st)
    {
        cout << i;
    }
    cout << endl;
    cout << lengthOfLongestSubstring(st);
}