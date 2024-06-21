// print matrix in spiral manner

#include <bits/stdc++.h>
using namespace std;

vector<int> Spiral(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> res;
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    while (top <= bottom && left <= right){
        for (int i = left; i <= right; i++)
            res.push_back(matrix[top][i]);
        top++;
        for (int i = top; i <= bottom; i++)
            res.push_back(matrix[i][right]);
        right--;
        if (top <= bottom){
            for (int i = right; i >= left; i--)
                res.push_back(matrix[bottom][i]);
            bottom--;
        }
        if (left <= right){
            for (int i = bottom; i >= top; i--)
                res.push_back(matrix[i][left]);
            left++;
        }
    }
    return res;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++){
        vector<int> temp;
        for (int j = 0; j < m; j++){
            int x;
            cin >> x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    vector<int> Res = Spiral(matrix);
    for (auto i : Res)
        cout << i << " ";
}