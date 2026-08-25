#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define imposi \
do{ \
    cout << 0; \
    return 0; \
}while(1)
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
const int MAXN=1000000;
int n,fact[MAXN+1],k,now;
string st;
int exp(int b,int e){
    int p=1;
    for(;e;e>>=1,b=1ll*b*b%MOD)if(e&1)p=1ll*p*b%MOD;
    return p;
}
int inversemod(int b){return exp(b,MOD-2);}
int combi(int x,int y){return 1ll*fact[x]*inversemod(fact[y])%MOD*inversemod(fact[x-y])%MOD;}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> st;
    k=st.size();
    if(n&1)imposi;
    fact[0]=1;
    for(int i=1;i<=MAXN;i++)fact[i]=1ll*fact[i-1]*i%MOD;
    for(auto u:st){
        if(u=='(')now++;
        else now--;
        if(now<0)imposi;
    }
    if(now>n-k)imposi;
    // llegar desde now hasta 0 en n-k pasos
    // cuantas formas hay?
    // total-malas
    // total=tengo que bajar now más de lo que hay para subir
    int subir=(n-k-now)/2,bajar=subir+now,tot=combi(subir+bajar,subir);
    // como contar malas?
    // las malas siempre tocan al -1 por lo menos una vez
    // si reflejamos las operaciones a partir del -1
    // entonces en vez de llegar a 0 llegariamos a -2
    // cantidad de veces de llegar de now a -2
    subir=(n-k-(now+2))/2,bajar=subir+now+2;
    int bad=combi(subir+bajar,subir);
    cout << (tot-bad+MOD)%MOD;
}