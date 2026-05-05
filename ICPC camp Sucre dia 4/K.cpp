#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,m,a,b,dp[1<<20][20];//visited subset, end i
bool edge[20][20];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    dp[1][0]=1;
    while(m--){
        cin >> a >> b;
        edge[--a][--b]=1;
    }
    ll maxi=(1<<n);
    for(ll mask=0;mask<maxi;mask++){
        for(ll i=0;i<n;i++){
            if(!(mask&(1<<i)))continue;
            if(!dp[mask][i])continue;
            // de i al j
            for(int j=0;j<n;j++){
                if(mask&(1<<j) || !edge[i][j])continue;
                dp[mask+(1<<j)][j]=(dp[mask+(1<<j)][j]+dp[mask][i])%MOD;
            }
        }
    }
    cout << (dp[maxi-1][n-1]%MOD+MOD)%MOD;
}
