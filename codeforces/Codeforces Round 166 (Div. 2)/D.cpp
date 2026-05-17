#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD1 1000000007
#define MOD2 1000000009
ll n,k,val[26];
string st,al;
bitset<26> good;
unordered_map<ll,ll> res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
    const ll A=uniform_int_distribution<ll> (1,MOD1-1)(rng);
    cin >> st >> al >> k;
    for(ll i=0;i<26;i++){
        good[i]=al[i]-'0';
        val[i]=uniform_int_distribution<ll> (1,MOD1-1)(rng);
    }
    n=st.size();
    for(ll i=0;i<n;i++){
        ll conbad=0,ha1=0,ha2=0;
        for(ll j=i;j<n;j++){
            conbad+=!good[st[j]-'a'];
            ha1=(A*ha1+val[st[j]-'a'])%MOD1;
            ha2=(A*ha2+val[st[j]-'a'])%MOD2;
            if(conbad<=k)res[ha1*A+ha2]=true;
        }
    }
    cout << res.size();
}