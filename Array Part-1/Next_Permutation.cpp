#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach :

// Step 1: Find all possible permutations of elements present and store them.
// Step 2: Search input from all possible permutations.
// Step 3: Print the next permutation present right after it.

// Better Approach

// void Next_Permutation(vector<int> &v){
//     next_permutation(v.begin(),v.end());
// }


// Optimal Approach TC-O(3N)
void Next_Permutation(vector<int> &v)
{
    int index = -1;
    int n = v.size();
    for (int i = n - 2; i >= 0; i--){
        if (v[i] < v[i + 1]) {
            index = i;
            break;
        }
    }
    if (index == -1) reverse(v.begin(), v.end());
    else{
        for (int i = n - 1; i > index; i--){
            if (v[i] > v[index]){
                swap(v[index], v[i]);
                break;
            }
        }
        reverse(v.begin() + index + 1, v.end());
    }
}

int main()
{
    vector<int> v;
    cout << "Enter Size of Vector" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    Next_Permutation(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}