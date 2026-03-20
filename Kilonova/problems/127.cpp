#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll A,B,res=1;
ll bigmod(ll b,ll e){
    ll p=1;
    while(e){
        if(e&1)p=p*b%MOD;
        e>>=1;
        b=b*b%MOD;
    }
    return p;
}
ll inversemod(ll b){
    return bigmod(b,MOD-2);
}
int main(){
    freopen("sumdiv.in","r",stdin);
    freopen("sumdiv.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> A >> B;
    vector<pair<ll,ll>> factorizacion;
    for(ll i=2;i*i<=A;i++){
        if(A%i==0){
            factorizacion.push_back({i,0});
            while(A%i==0){
                factorizacion.back().second++;
                A/=i;
            }
        }
    }
    if(A>1)factorizacion.push_back({A%MOD,1});
    // cada factoriazaion.second*=B
    //(p^(e*B+1)-1)/(p-1);
    /*
    (((p^e)^B)*p-1)*inversemod(p-1);
    */
    for(auto u:factorizacion){
        //cout << u.first << ' ' << u.second << '\n';
        ll p;
        if(u.first==1)p=(B%MOD*u.second%MOD+1)%MOD;
        else p=(bigmod(bigmod(u.first,u.second),B)*u.first%MOD-1+MOD)%MOD*inversemod((u.first-1+MOD)%MOD)%MOD;
        res=res*p%MOD;
    }
    cout << res;
}