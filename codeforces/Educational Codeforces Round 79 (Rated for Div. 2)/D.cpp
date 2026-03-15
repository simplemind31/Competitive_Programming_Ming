#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
int n,k,can[1000000],a;
ll prob,res[1000000];
ll bigmod(ll b,ll e){
    ll p=1;
    while(e){
        if(e&1)p=(p*b)%MOD;
        b=(b*b)%MOD;
        e>>=1;
    }
    return p;
}
ll inversemod(ll b){return bigmod(b,MOD-2);}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    // probabilidad de que me de item y=(sumatoria de 1/n*1/ki) si existe y en el kid i->1/n*sumatoria de 1/ki
    for(int i=0;i<n;i++){
        cin >> k;
        ll inverso=inversemod(k);
        for(int j=0;j<k;j++){
            cin >> a;
            can[--a]++;
            res[a]=(res[a]+inverso)%MOD;
        }
    }
    for(int i=0;i<1000000;i++)prob=(prob+(can[i]*res[i])%MOD)%MOD;
    prob=prob*inversemod(1ll*n*n%MOD)%MOD;
    cout << prob;
}