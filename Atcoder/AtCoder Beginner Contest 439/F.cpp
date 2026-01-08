#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 998244353
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int n,nums[300001];
pair<ll,ll> res[300001];
ll pow2[300001],acum,fina;
ll bigmod(ll b ,ll e){
    ll p=1;
    while(e){
        if(e&1)p=(p*b)%MOD;
        e>>=1;
        b=(b*b)%MOD;
    }
    return p;
}
int main(){
    intset x,y;
    cin >> n;
    pow2[0]=1;
    for(int i=1;i<=300000;i++){
        pow2[i]=(pow2[i-1]<<1)%MOD;
    }
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    for(int i=n-1;i>=0;i--){
        res[i].first=acum;
        res[i].second=(x.order_of_key(nums[i])*pow2[i])%MOD;
        acum+=res[i].second;
        acum%=MOD;
        x.insert(nums[i]);
    }
    for(int i=0;i<n;i++){
        fina+=((y.order_of_key(nums[i])*res[i].second)%MOD)*bigmod(pow2[i],MOD-2)%MOD;
        fina%=MOD;
        fina+=((y.order_of_key(nums[i])*res[i].first)%MOD)*bigmod(pow2[i+1],MOD-2)%MOD;
        fina%=MOD;
        y.insert(nums[i]);
    }
    cout << fina;
}