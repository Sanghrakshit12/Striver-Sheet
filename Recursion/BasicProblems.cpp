#include <bits/stdc++.h>
using namespace std;
//  print name n times TC-O(n) SC-O(n) 
void printname(int c, int n)
{
    if (c> n)
        return;
    cout << "Sangah" << endl;
    printname(++c,n);
}

//  print  1 to n  TC-O(n) SC-O(n) 
void printnum(int c, int n)
{
    if (c> n)
        return;
    cout << c<< endl;
    printnum(++c,n);
}

//  print  n to 1  TC-O(n) SC-O(n) 
void printrev(int n)
{
    if (n==0)
        return;
    cout << n<< endl;
    printrev(--n);
}


//  print  1 to n  TC-O(n) SC-O(n)  BAcktracking
void printback(int c, int n)
{
    if (c==0)
        return;
    printback(c-1,n);
    cout << c<< endl;
}

//  print  n to 1  TC-O(n) SC-O(n)  Backtrack
void printrevback(int c,int n)
{
    if(c>n) return;
    printrevback(c+1,n);
    cout<<c<<" ";
}

int main()
{
    int n;
    cin >> n;
    printrevback(1,n);
    return 0;
}