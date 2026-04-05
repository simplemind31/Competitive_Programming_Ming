#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int t,n,fact[2000001],invfact[2000001],x;
int bigmod(int b,int e){
    int p=1;
    while(e){
        if(e&1)p=1ll*p*b%MOD;
        b=1ll*b*b%MOD;
        e>>=1;
    }
    return p;
}
int inversemod(int b){return bigmod(b,MOD-2);}
int combi(int a,int b){return 1ll*fact[a]*invfact[b]%MOD*invfact[a-b]%MOD;}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fact[0]=1;
    for(int i=1;i<=2000000;i++)fact[i]=1ll*fact[i-1]*i%MOD;
    invfact[2000000]=inversemod(fact[2000000]);
    for(int i=1999999;i>=0;i--)invfact[i]=1ll*invfact[i+1]*(i+1)%MOD;
    cin >> t;
    for(int caso=1;caso<=t;caso++){
        cout << "Case " << caso << ": ";
        cin >> n;
        int suma=0,res=1;
        while(n--){
            cin >> x;
            res=1ll*res*combi(suma+x-1,x-1)%MOD;
            suma+=x;
        }
        cout << res << '\n';
    }
}