#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
int n,m;
ll dp[1001][11][1<<10];
// estoy en la columna i donde la fila i sobresale y la i+1 no y donde los bits de k sale del borde
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    //caso base, definir el tile [0][0]
    dp[0][0][1]=dp[0][0][2]=1;
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            for(int k=0;k<(1<<n);k++){
                if(k&(1<<((i+1)%n))){
                    dp[j+(i+1)/n][(i+1)%n][k-(1<<((i+1)%n))]=(dp[j+(i+1)/n][(i+1)%n][k-(1<<((i+1)%n))]+dp[j][i][k])%MOD;
                    continue;
                }
                //definir el sentido del siguiente tile
                // ponerlo horizontal
                dp[j+(i+1)/n][(i+1)%n][k+(1<<((i+1)%n))]=(dp[j+(i+1)/n][(i+1)%n][k+(1<<((i+1)%n))]+dp[j][i][k])%MOD;
                // ponerlo vertical hacia abajo
                if((i+1)%n+1<n && !(k&(1<<((i+1)%n+1))))dp[j+(i+1)/n][(i+1)%n][k+(1<<((i+1)%n+1))]=(dp[j+(i+1)/n][(i+1)%n][k+(1<<((i+1)%n+1))]+dp[j][i][k])%MOD;
            }
        }
    }
    cout << dp[m-1][n-1][0];
}