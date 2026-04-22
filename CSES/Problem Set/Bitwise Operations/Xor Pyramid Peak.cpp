#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int MAXN=200000;
int n,fact[MAXN+1],invfact[MAXN+1],a;
int bigmod(int b,int e){
    int p=1;
    for(;e;e>>=1,b=1ll*b*b%MOD)if(e&1)p=1ll*p*b%MOD;
    return p;
}
int inversemod(int b){return bigmod(b,MOD-2);}
int combi(int n,int k){return 1ll*fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    fact[0]=1;
    for(int i=1;i<=MAXN;i++)fact[i]=1ll*fact[i-1]*i%MOD;
    invfact[MAXN]=inversemod(fact[MAXN]);
    for(int i=MAXN-1;i>=0;i--)invfact[i]=1ll*invfact[i+1]*(i+1)%MOD;
    for(int i=0;i<n;i++){
        cin >> a;
        
    }
}