// At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
// Note that you do not have any change in hand at first.
// Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int> &bills){
    int n = bills.size();
    if (bills[0] != 5)
        return 0;
    int i = 1, j = 0;
    for (int p = 1; p < n; p++){
        if (bills[p] == 5)
            i++;
        else if (bills[p] == 10){
            if (i == 0)
                return 0;
            i--;
            j++;
        }
        else{
            if (j != 0){
                j--;
                if (i == 0)
                    return 0;
                i--;
            }
            else{
                if (i < 3)
                    return 0;
                i -= 3;
            }
        }
    }
    return 1;
}

int main(){
    vector<int> v1;
    cout << "Enter Size of Vectors" << endl;
    int n;
    cin >> n;
    cout << "Enter first Vector" << endl;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v1.push_back(x);
    }
    cout<<lemonadeChange(v1);
}