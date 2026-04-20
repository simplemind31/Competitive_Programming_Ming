#include <bits/stdc++.h>
#define MOD 10000007
using namespace std;
typedef long long ll;
ll bigmod(ll b,ll e){
    ll p=1;
    while(e){
        if(e&1)p=p*b%MOD;
        b=b*b%MOD;
        e>>=1;
    }
    return p;
}
ll n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(1){
        cin >> n >> m;
        if(n==0 && m==0)break;
        if(n==1)cout << "1\n";
        cout << (2*bigmod(n-1,n-1)+bigmod(n,n)+bigmod(n,m)+2*bigmod(n-1,m))%MOD << '\n';
    }
}