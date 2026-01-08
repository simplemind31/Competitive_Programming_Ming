#include <bits/stdc++.h>
using namespace std;
int m,n,dp[1001][1001],x[1000],y[1000];
vector<int> res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> m >> n;
    for(int i=0;i<m;i++)cin >> x[i];
    for(int i=0;i<n;i++)cin >> y[i];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[m][n] << '\n';
    while(m && n){
        if(x[m-1]==y[n-1]){
            res.push_back(x[m-1]);
            m--;n--;
        }else if(dp[m-1][n]>dp[m][n-1])m--;
        else n--;
    }
    reverse(res.begin(),res.end());
    for(auto u:res)cout << u << ' ';
}