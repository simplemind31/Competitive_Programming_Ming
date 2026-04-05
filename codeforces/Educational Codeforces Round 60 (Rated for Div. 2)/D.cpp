#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,m,fact[1000001],invfact[1000001];
ll bigmod(ll b,ll e){
    ll p=1;
    while(e){
        if(e&1)p=p*b%MOD;
        b=b*b%MOD;
        e>>=1;
    }
    return p;
}
ll inversemod(ll b){
    return bigmod(b,MOD-2);
}
ll combi(ll a,ll b){
    return fact[a]*invfact[b]%MOD*invfact[a-b]%MOD;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fact[0]=1;
    for(int i=1;i<=1000000;i++)fact[i]=fact[i-1]*i%MOD;
    invfact[1000000]=inversemod(fact[1000000]);
    for(int i=999999;i>=0;i--){
        invfact[i]=invfact[i+1]*(i+1)%MOD;
    }
    cin >> n >> m;
    // sumatoria de n-i(m-1) choose i?
    m--;
    ll res=0;
    for(int i=0;n-i*m>=i;i++){
        res+=combi(n-i*m,i);
    }
    cout << res;
}