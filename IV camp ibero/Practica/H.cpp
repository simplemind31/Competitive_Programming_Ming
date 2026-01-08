#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int t,l,r,k;
ll bigmod(ll b,ll e){
    ll p=1;
    while(e){
        if(e&1){
            p=(p*b)%MOD;
        }
        b=(b*b)%MOD;
        e/=2;
    }
    return p;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> l >> r >> k;
        cout << ((bigmod(9/k+1,r)-bigmod(9/k+1,l))+MOD)%MOD << '\n';
    }
}