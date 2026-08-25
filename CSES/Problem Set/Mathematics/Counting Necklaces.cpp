#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
const int MAXN=1000000;
int n,m,fact[MAXN+1],invfact[MAXN+1],res[MAXN+1],fina;
vector<int> primes;
bitset<MAXN+1> criba;
int exp(int b,int e){
    int p=1;
    for(;e;e>>=1,b=1ll*b*b%MOD)if(e&1)p=1ll*p*b%MOD;
    return p;
}
int inversemod(int b){return exp(b,MOD-2);}
int combi(int x,int y){return 1ll*fact[x]*invfact[y]%MOD*inversemod(fact[x-y])%MOD;}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fact[0]=1;
    for(int i=1;i<=MAXN;i++)fact[i]=1ll*fact[i-1]*i%MOD;
    invfact[MAXN]=inversemod(fact[MAXN]);
    for(int i=MAXN-1;i>=0;i--)invfact[i]=1ll*invfact[i+1]*(i+1)%MOD;
    criba[0]=criba[1]=1;
    for(int i=2;i<=MAXN;i++){
        if(!criba[i])primes.push_back(i);
        for(int j=0;j<primes.size() && i*primes[j]<=MAXN;j++){
            criba[i*primes[j]]=1;
            if(i%primes[j]==0)break;
        }
    }
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        if(n%i)continue;
        res[i]=exp(m,i);
        for(int j=1;j*j<=i;j++){
            if(i%j)continue;
            if(j!=i)res[i]=(res[i]-res[j]+MOD)%MOD;
            if(j*j!=i && (i/j)!=i)res[i]=(res[i]-res[i/j]+MOD)%MOD;
        }
        fina=(fina+1ll*res[i]*inversemod(i))%MOD;
    }
    cout << fina;
}