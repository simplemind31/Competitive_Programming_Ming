#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int k,sum,res=1,c;
int fact[2001],invfact[2001];
int bigmod(int b,int e){
    int p=1;
    while(e){
        if(e&1)p=1ll*p*b%MOD;
        e>>=1;
        b=1ll*b*b%MOD;
    }
    return p;
}
int inversemod(int a){return bigmod(a%MOD,MOD-2);}
int combi(int a,int b){return 1ll*fact[a]*invfact[b]%MOD*invfact[a-b]%MOD;}
int main(){
    // now=prob igual
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fact[0]=1;
    for(int i=1;i<=2000;i++)fact[i]=1ll*fact[i-1]*i%MOD;
    invfact[2000]=inversemod(fact[2000]);
    for(int i=1999;i>=0;i--)invfact[i]=1ll*invfact[i+1]*(i+1)%MOD;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> c;
        res=1ll*res*combi(sum+c-1,c-1)%MOD;
        sum+=c;
    }
    cout << res;
}
// ABBCCCDDDD