#include <bits/stdc++.h>
using namespace std;
int t,a,b,c;
int bigmod(int b,int e,int mod){
    int p=1;
    while(e){
        if(e&1)p=p*b%mod;
        b=b*b%mod;
        e>>=1;
    }
    return p;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        cout << bigmod(a,b,c) << '\n';
    }
}