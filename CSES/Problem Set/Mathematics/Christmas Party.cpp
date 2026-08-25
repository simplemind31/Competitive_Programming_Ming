#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n;
ll dp[1000001][2];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    /*
    dp[n][2]= la cantidad de formas cuando son n personas y la primera persona está forzado a dar su regalo a alguien
    la persona 1 da el regalo a la persona x
    la persona 1 o recibe el regalo de x o recibe de otra persona y
    si recibe de x entonces solve(n-2);
    si recibe de y entonces y-1->x podemos pensar que y dio el regalo a x
    dp[n][0]=(n-1)*(dp[n-2][0]+(n-2)dp[n-1][1]);
    dp[n][1]=dp[n-2][0]+(n-2)dp[n-1][1];
    */
    cin >> n;
    dp[0][0]=dp[0][1]=1;
    for(int i=2;i<=n;i++)dp[i][0]=(i-1)*(dp[i][1]=(dp[i-2][0]+(i-2)*dp[i-1][1])%MOD)%MOD;
    cout << dp[n][0];
}