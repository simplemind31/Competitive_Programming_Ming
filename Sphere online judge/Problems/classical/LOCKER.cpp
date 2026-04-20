#include <bits/stdc++.h>
#define MOD 1000000007
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
ll n,m,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        if(n==1)cout << "1\n";
        else if(n%3==0)cout << bigmod(3,n/3) << '\n';
        else if(n%3==1)cout << bigmod(3,(n-4)/3)*4%MOD << '\n';
        else cout << bigmod(3,(n-2)/3)*2%MOD << '\n';
    }
}