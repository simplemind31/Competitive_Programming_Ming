#include <iostream>
#include <vector>
#include <numeric>
#define MOD 998244353
using namespace std;
typedef long long ll;
const ll MAXN=500000;
ll t,n,m,k,fact[MAXN+1],invfact[MAXN+1];
ll bigmod(ll b,ll e){
    ll p=1;
    while(e){
        if(e&1)p=1ll*p*b%MOD;
        b=1ll*b*b%MOD;
        e>>=1;
    }
    return p;
}
ll inversemod(ll b){return bigmod(b,MOD-2);}
ll combi(ll n,ll k){return 1ll*fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fact[0]=1;
    for(ll i=1;i<=MAXN;i++)fact[i]=1ll*i*fact[i-1]%MOD;
    invfact[MAXN]=inversemod(fact[MAXN]);
    for(ll i=MAXN-1;i>=0;i--)invfact[i]=1ll*invfact[i+1]*(i+1)%MOD;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        ll res=0;
        for(ll i=0;i<=m && k+m-1-n*i>=m-1;i++){
            if(i&1)res=(res-1ll*combi(m,i)*combi(k+m-1-n*i,m-1)%MOD+MOD)%MOD;
            else res=(res+1ll*combi(m,i)*combi(k+m-1-n*i,m-1))%MOD;
        }
        cout << res << '\n';
    }
}