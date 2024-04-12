#include <bits/stdc++.h>
using namespace std;

// Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
int Variation1(int r, int c)
{
    int res=1;
    for(int i=0;i<c;i++){
        res*=(r-i);
        res/=i+1;
    }
    return res;
}

// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.
int Variation2()
{
}

// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.
int Variation3()
{
}
int main()
{
    cout << "Enter row no and coloum Number for Variation 1" << endl;
    int r, c;
    cin >> r >> c;
    cout<<Variation1(r-1, c-1);
}