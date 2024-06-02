// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s){
    int n = g.size();
    int m = s.size();
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0;
    while (i < n && j < m){
        if (s[j] >= g[i])
            i++;
        j++;
    }
    return i;
}

int main(){
    vector<int> v1;
    vector<int> v2;
    cout << "Enter Size of Vectors" << endl;
    int n, m;
    cin >> n >> m;
    cout << "Enter first Vector" << endl;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v1.push_back(x);
    }
    cout << "Enter Second Vector" << endl;
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        v2.push_back(x);
    }
    cout<<findContentChildren(v1, v2);
}