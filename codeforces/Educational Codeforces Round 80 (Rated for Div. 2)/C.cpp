#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n,m,fact[2001],invfact[2001],res;
int bigmod(int b,int e){
    int p=1;
    while(e){
        if(e&1)p=1ll*p*b%MOD;
        b=1ll*b*b%MOD;
        e>>=1;
    }
    return p;
}
int inversemod(int b){
    return bigmod(b,MOD-2);
}
int combi(int a,int b){
    return 1ll*fact[a]*invfact[b]%MOD*invfact[a-b]%MOD;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    fact[0]=1;
    for(int i=1;i<=2000;i++)fact[i]=1ll*fact[i-1]*i%MOD;
    invfact[2000]=inversemod(fact[2000]);
    for(int i=1999;i>=0;i--)invfact[i]=1ll*invfact[i+1]*(i+1)%MOD;
    for(int i=1;i<=n;i++)res=(res+1ll*combi(i+m-2,i-1)*combi(n-i+m,n-i)%MOD)%MOD;
    cout << res;
}