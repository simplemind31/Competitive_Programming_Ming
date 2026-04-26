#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n,MOD;
int bigmod(int b,int e){
    if(b==0)return 0;
    int p=1;
    for(;e;e>>=1,b=1ll*b*b%MOD)if(e&1)p=1ll*p*b%MOD;
    return p;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("exercise.in","r",stdin);
    //freopen("exercise.out","w",stdout);
    cin >> n >> MOD;
    // sumatoria de todo k tal que lcm(a1,a2,a3,...,ax)=k ademas n es una combinacion lineal de a1,a2,...,ax
    // -> cada potencia de k aparece en ai como multiplo
    // -> cada ai es mejor que sea potencia de k para la combinacion lineal
    // -> hay a lo mucho log(k) ai
    // para todo k<=n es posible
    // para un n,encontrar ais tal que n es combinacion lineal de ai, k=lcm(ai)
    // warning !! n no necesariamente debe ser combinacion lineal, porque si tengo ciclos de 1 entonces <=n
    // -> a1+a2+a3+...+ax<=n 
}