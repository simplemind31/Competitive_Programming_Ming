#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int MAXN=1000000;
int n,k,fact[2*MAXN+1];
int bigmod(int b,int e){
    int p=1;
    for(;e;e>>=1,b=1ll*b*b%MOD)if(e&1)p=1ll*p*b%MOD;
    return p;
}
int inversemod(int b){return bigmod(b,MOD-2);}
int combi(int n,int k){
    return 1ll*fact[n]*inversemod(fact[k])%MOD*inversemod(fact[n-k])%MOD;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    fact[0]=1;
    for(int i=1;i<=2*MAXN;i++)fact[i]=1ll*i*fact[i-1]%MOD;
    cout << combi(n+k-1,n-1);
}