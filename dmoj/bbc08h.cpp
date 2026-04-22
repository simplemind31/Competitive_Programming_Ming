#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n;
int bigmod(int b,int e){
    int p=1;
    for(;e;e>>=1,b=1ll*b*b%MOD)if(e&1)p=1ll*p*b%MOD;
    return p;
}
int inversemod(int b){return bigmod(b,MOD-2);}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int fact[2*n+3];
    fact[0]=1;
    for(int i=1;i<=2*n+2;i++)fact[i]=1ll*fact[i-1]*i%MOD;
    cout << (1ll*fact[2*n+2]*inversemod(fact[n+1])%MOD*inversemod(fact[n+1]%MOD)-1+MOD)%MOD;
}