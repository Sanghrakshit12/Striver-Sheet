
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >>m>> n;
    while(n>0 &&m>0){
        if(m>n) m=m%n;
        else n=n%m;  
    }
    if(m==0) cout<<n;
    else cout<<m;
}