#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    bool xd=false;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            if(xd)cout << "x";
            xd=true;
            cout << i;
            n/=i;
        }
    }
    if(n>1){
        if(xd)cout << "x";
        cout << n;
    }
}