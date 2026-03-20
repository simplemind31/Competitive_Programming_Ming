#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int MAXN=100000;
int n,fact[2*MAXN+1],res;
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
    return 1ll*fact[a]*inversemod(1ll*fact[a-b]*fact[b]%MOD)%MOD;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fact[0]=1;
    for(int i=1;i<=2*MAXN;i++){
        fact[i]=1ll*fact[i-1]*i%MOD;
    }
    // elijo y -----------...--- i-1/ -> -> -> ... -> -> n-1
    // combi de n+i-2 en i-1
    cin >> n;
    for(int i=1;i<=n;i++){
        res=(res+combi(n+i-2,i-1))%MOD;
    }
    res=res*2%MOD;
    res=(res-n+MOD)%MOD;
    cout << res;
}