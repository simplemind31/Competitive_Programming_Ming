#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
const int MAXN=100000;
int fact[MAXN+1],t,n;
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
int combi(int x,int y){
    return 1ll*fact[x]*inversemod(1ll*fact[y]*fact[x-y]%MOD)%MOD;
}
int main(){
    fact[0]=1;
    for(int i=1;i<=MAXN;i++)fact[i]=1ll*i*fact[i-1]%MOD;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1;i<=n;i++){
            if(i==1 || n<2*i-1){
                cout << "0 ";
                continue;
            }
            cout << 1ll*fact[2*i-2]*combi(n-i-1,i-2)%MOD*fact[n-(2*i-2)+1]%MOD << ' ';
        }
        cout << '\n';
    }
}