#include <bits/stdc++.h>
using namespace std;

void UnionBrute(vector<int> v1, vector<int> v2){
    set<int> s;
    for (int i = 0; i < v1.size(); i++)
        s.insert(v1[i]);
    for (int i = 0; i < v2.size(); i++)
        s.insert(v2[i]);
    for (int i : s)
        cout << i << " ";
}

vector<int> OptimalUnion(vector<int> v1, vector<int> v2){
    int n = v1.size();
    int m = v2.size();
    vector<int> res;
    int i = 0, j = 0;
    while (i < n && j < m){
        if (v1[i] <= v2[j]){
            if (res.empty() || v1[i] != res.back())
                res.push_back(v1[i]);
            i++;
        }
        else{
            if (res.empty() || v2[j] != res.back())
                res.push_back(v2[j]);
            j++;
        }
    }
    while (i < n){
        if (res.empty() || v1[i] != res.back())
            res.push_back(v1[i]);
        i++;
    }
    while (j < m){
        if (res.empty() || v2[j] != res.back())
            res.push_back(v2[j]);
        j++;
    }
    return res;
}

int main()
{
    vector<int> v1 = {2, 2, 3, 4, 5};
    vector<int> v2 = {1, 2, 3, 4, 5};
    UnionBrute(v1, v2);
    cout<<endl;
    vector<int> res = OptimalUnion(v1, v2);
    for (auto i : res)
        cout << i << " ";
}