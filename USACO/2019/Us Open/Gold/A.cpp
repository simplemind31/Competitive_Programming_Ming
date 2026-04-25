#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    cin >> n >> c;
    int nums[n+1];
    for(int i=1;i<=n;i++)cin >> nums[i];
    ll dp[n+1][c+2];
    for(int i=0;i<=n;i++)for(int j=0;j<=c+1;j++)dp[i][j]=1e18;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        int maxi=0;
        ll suma=0;
        for(int j=i;j>0;j--){
            //del i al j un nuevo net
            maxi=max(maxi,nums[j]);
            suma+=nums[j];
            for(int k=1;k<=c+1;k++){
                dp[i][k]=min(dp[i][k],dp[j-1][k-1]+1ll*maxi*(i-j+1)-suma);
            }
        }
    }
    ll res=1e18;
    for(int i=0;i<=c+1;i++){
        res=min(res,dp[n][i]);
    }
    cout << res;
}