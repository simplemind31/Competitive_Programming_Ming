#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,a,n,MOD;
ll bigmod(ll b,ll e){
    ll p=1;
    while(e){
        if(e&1)p=p*b%MOD;
        b=b*b%MOD;
        e>>=1;
    }
    return p;
}
ll inversemod(ll b){return bigmod(b,MOD-2);}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(1){
        cin >> x >> a >> n >> MOD;
        if(!(x+a+n+MOD))break;
        cout << (x*bigmod(a,n)%MOD-(bigmod(a,n+1)-1)*inversemod(a-1)%MOD+1+MOD)%MOD << '\n';
    }
}