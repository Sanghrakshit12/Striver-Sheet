#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<endl;
            if(n/i!=i){
                cout<<n/i<<endl;
            }
        }
    }
    return 0;
}