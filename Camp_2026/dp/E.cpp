#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
vector<vector<ll>> mat;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    mat.assign(n+1,vector<ll>(m+1));
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin >> mat[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+mat[i][j];
        }
    }
    cout << dp[n][m];
}
// 10+3+4+15+6+1=39