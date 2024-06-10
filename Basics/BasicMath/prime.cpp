#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int c=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            c++;
            if(n/i!=i){
                c++;
            }
        }
    }
    if(c==2) cout<<"Prime"<<endl;
    else cout<<"Not Prime"<<endl;
    return 0;
}