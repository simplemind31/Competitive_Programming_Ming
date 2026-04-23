#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
int t;
ll n,x;
ll con0(ll m){return (m+1)/4+1;}
ll con1(ll m){return (m+3)/4;}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> x;
        ll iz0=con0(x-1),iz1=con1(x-1),de0=con0(n)-iz0,de1=con1(n)-iz1;
        cout << (iz0%MOD*(de0%MOD)+iz1%MOD*(de1%MOD))%MOD << '\n';
    }
}