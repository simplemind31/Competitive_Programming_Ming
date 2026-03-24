#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,m;
ll res=0,now=1;
ll bigmod(ll b,ll e){
    ll p=1;
    b%=MOD;
    while(e){
        if(e&1)p=p*b%MOD;
        e>>=1;
        b=b*b%MOD;
    }
    return p;
}
ll inversemod(ll a){
    return bigmod(a%MOD,MOD-2);
}
int main(){
    // now=prob igual
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    ll a[n],b[n];
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++)cin >> b[i];
    for(int i=0;i<n;i++){
        if(a[i]==0 && b[i]==0)res=(res+now*(m-1)%MOD*inversemod(2*m%MOD)%MOD)%MOD;
        else if(a[i]==0)res=(res+now*(m-b[i])%MOD*inversemod(m)%MOD)%MOD;
        else if(b[i]==0)res=(res+now*(a[i]-1)%MOD*inversemod(m)%MOD)%MOD;
        else{
            if(a[i]==b[i])continue;
            if(a[i]>b[i])res=(res+now)%MOD;
            break;
        }
        now=now*inversemod(m)%MOD;
    }
    cout << res;
}