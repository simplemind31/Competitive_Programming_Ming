#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
const int MAXN=1000000;
ll n;
int exp(int b,ll e){
    int p=1;
    for(;e;e>>=1,b=1ll*b*b%MOD)if(e&1)p=1ll*p*b%MOD;
    return p;
}
int inversemod(int b){return exp(b,MOD-2);}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //burnside's lemma 1/|G|*sum(x^g) g belongs to G
    cin >> n;
    cout << 1ll*(1ll*exp(2,n*n)+2*exp(2,(n*n-1)/4+1)+exp(2,(n*n-1)/2+1))%MOD*inversemod(4)%MOD;
}