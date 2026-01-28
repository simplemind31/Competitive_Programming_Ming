#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char c;
int n,k,maxi;
int dp[100001][3][21];
//maximum number of wins in i,with j and cahnged k times;
//h=0
//p=1
//s=2
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            for(int ii=0;ii<3;ii++){
                for(int l=0;l<=k;l++){
                    // cambie de ii a j
                    if(l)dp[i][j][l]=max(dp[i][j][l],dp[i-1][ii][l-1]);
                    if(ii==j)dp[i][j][l]=max(dp[i][j][l],dp[i-1][ii][l]);
                }
            }
        }
        cin >> c;
        for(int l=0;l<=k;l++)dp[i][(c=='H')?0:((c=='P')?1:2)][l]++;
    }
    for(int j=0;j<3;j++)maxi=max(maxi,dp[n][j][k]);
    cout << maxi;
}