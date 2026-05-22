#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,k,res;
int bigmod(int b,int e){
    int p=1;
    for(;e;e>>=1,b=1ll*b*b%MOD)if(e&1)p=1ll*p*b%MOD;
    return p;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    k--;
    int nums[n+1],ssum0[n+1];
    nums[0]=-1;
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        if(nums[i]==2)nums[i]=0;
        else if(nums[i]==4)nums[i]=1;
        else nums[i]=-1;
    }
    ssum0[n]=0;
    for(int i=n-1;i>=0;i--)ssum0[i]=ssum0[i+1]+(nums[i+1]==-1);
    int dp[n+1][2048];
    memset(dp,0,sizeof(dp));
    // 3
    // 1 0 -1 1 1 -1
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int mask=0;mask<2048;mask++){
            if(mask && 31-__builtin_clz(mask)==k){
                // lo que esta despues podemos poner lo que quiero
                res=(res+1ll*dp[i-1][mask]*bigmod(2,ssum0[i-1])%MOD)%MOD;
                //cout << dp[i-1][mask]*bigmod(2,ssum0[i]) << '\n';
                dp[i-1][mask]=0;
                continue;
            }
            if(nums[i]==0){
                if(mask+1<2048)dp[i][mask+1]=(dp[i][mask+1]+dp[i-1][mask])%MOD;
            }else if(nums[i]==1){
                if(mask&1){
                    // formar un nuevo bloque
                    dp[i][2]=(dp[i][2]+dp[i-1][mask])%MOD;
                }else{
                    // continuar el bloqued
                    if(mask+2<2048)dp[i][mask+2]=(dp[i][mask+2]+dp[i-1][mask])%MOD;
                }
            }else{
                if(mask+1<2048)dp[i][mask+1]=(dp[i][mask+1]+dp[i-1][mask])%MOD;
                if(mask&1){
                    // formar un nuevo bloque
                    dp[i][2]=(dp[i][2]+dp[i-1][mask])%MOD;
                }else{
                    // continuar el bloque
                    if(mask+2<2048)dp[i][mask+2]=(dp[i][mask+2]+dp[i-1][mask])%MOD;
                }
            }
        }
    }
    for(int mask=1;mask<2048;mask++){
        if(31-__builtin_clz(mask)>=k){
            res=(res+dp[n][mask])%MOD;
        }
    }
    cout << res;
}//(2->1,4->2)
//2000 2s = 22222...222 =1000 4s =500 8s=250 16 =125 32=62 64=31 128=15 256=7 512=3 1024=1 2048
//10022
/*
11022
2022
76521
si un 2 sigue del 1, entonces empieza un nuevo bloque
si hay una cantidad impar de 1 consecutivos, entonces genera un nuevo bloque
// dentro de un bloque el máximo se puede determinar por la cantidad de 1 y 2 que hay
para evitar formar nuevos bloques se debe haber siempre consecutivo par de 1
dp[i][j]
cantidad de formas para llegar a la posicion i tal que el ultimo bloque empezó en la posicion j
// sumar en bits

>>>>>>cantidad de fomas para llegar a la poscion i tal que la suma de bit es j

741
1111211
211211
22211
3211
322
33
4
*/ 

