#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int MAXN=1000000;
int n,m,fact[2*MAXN+1],pow25[MAXN+1],pow26[MAXN+1],invfact[2*MAXN+1],res;
int bigmod(int b,int e){
    int p=1;
    for(;e;e>>=1,b=1ll*b*b%MOD)if(e&1)p=1ll*p*b%MOD;
    return p;
}
int inversemod(int b){return bigmod(b,MOD-2);}
int combi(int n,int k){return 1ll*fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;}
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> s;
    m=s.size();
    fact[0]=pow25[0]=pow26[0]=1;
    for(int i=1;i<=MAXN;i++){
        fact[i]=1ll*fact[i-1]*i%MOD;
        pow25[i]=1ll*pow25[i-1]*25%MOD;
        pow26[i]=1ll*pow26[i-1]*26%MOD;
    }
    for(int i=MAXN+1;i<=2*MAXN;i++)fact[i]=1ll*fact[i-1]*i%MOD;
    invfact[2*MAXN]=inversemod(fact[2*MAXN]);
    for(int i=2*MAXN-1;i>=0;i--)invfact[i]=1ll*invfact[i+1]*(i+1)%MOD;
    // oof, solo usar o antes de primer o o después del ultimo?, solo usar f antes del primer f
    //oofb
    //ooooffobb
    // si pongo el la misma letra al lado de ese, tiene que ser antes, pero puedo poner en otros secotres
    //oofofb
    // usar ultima aparicion como base
    // en la posicion f, uso todo menos f y luego uso f, luego uso todo menos o luego o luego todo menos o luego o luego cualquier letra
    // si hay x letras al principio, entonces sobra n-x letras para completar, enotnces hay combi(n-x+m,m)*25**(n-x)*26**x
    // la primera letra siempre queda despues de i
    for(int i=0;i<=n;i++)res=(res+1ll*combi(n-i+m-1,m-1)*pow25[n-i]%MOD*pow26[i]%MOD)%MOD;
    cout << res;
}