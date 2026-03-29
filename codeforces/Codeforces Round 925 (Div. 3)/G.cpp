#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
const int MAXN=1000000;
int t,a,b,c,d,fact[2*MAXN+1],invfact[2*MAXN+1];
int bigmod(int b,int e){
    int p=1;
    while(e){
        if(e&1)p=1ll*p*b%MOD;
        e>>=1;
        b=1ll*b*b%MOD;
    }
    return p;
}
int inversemod(int b){return bigmod(b,MOD-2);}
int combi(int n,int k){return 1ll*fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fact[0]=1;
    for(int i=1;i<=2*MAXN;i++)fact[i]=1ll*fact[i-1]*i%MOD;
    invfact[2*MAXN]=inversemod(fact[2*MAXN]);
    for(int i=2*MAXN-1;i>=0;i--)invfact[i]=1ll*invfact[i+1]*(i+1)%MOD;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;
        if(b>a)swap(a,b);
        if(a-b>1)cout << "0\n";
        else if((a>0)+(b>0)+(c>0)+(d>0)<=1)cout << "1\n";
        else if(a==b)cout << (1ll*combi(c+a,c)*combi(d+a-1,d)+1ll*combi(c+a-1,c)*combi(d+a,d))%MOD << '\n';
        else cout << 1ll*combi(c+a-1,c)*combi(d+a-1,d)%MOD << '\n';
    }
}