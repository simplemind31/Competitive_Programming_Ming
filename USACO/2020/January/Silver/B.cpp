#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool solve(ll n,ll k,ll m,ll x){
    ll g=0;
    while((n-g)>0 && k){
        ll sobra=n-g;
        ll val=sobra/x;
        if(val<=m){
            g+=k*m;
            k=0;
            break;
        }
        // restan de val en val
        // sob,...,ulti=(sob-sob%x)
        ll ulti=sobra-(sobra%x);
        ll cantidia=1+(sobra-ulti)/val;
        if(cantidia<=k){
            k-=cantidia;
            g+=cantidia*val;
        }else{
            g+=k*val;
            k=0;
        }
    }
    return (n-g)<=0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("loan.in","r",stdin);
    freopen("loan.out","w",stdout);
    ll n,k,m;
    cin >> n >> k >> m;
    // una vez que use m tendre que usar hasta 0
    ll l=1,r=1e12;
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(solve(n,k,m,mid))l=mid;
        else r=mid-1;
    }
    cout << l;
}