#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int n,m;
ll res,dp[2][50001][1002];
pair<int,ll> nums[1001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> nums[i].first >> nums[i].second;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            dp[0][j][i]=dp[0][j][i-1];
            if(j-nums[i].first>=0)dp[0][j][i]=max(dp[0][j][i],dp[0][j-nums[i].first][i-1]+nums[i].second);
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=0;j--){
            dp[1][j][i]=dp[1][j][i+1];
            if(j-nums[i].first>=0)dp[1][j][i]=max(dp[1][j][i],dp[1][j-nums[i].first][i+1]+nums[i].second);
        }
    }
    res=dp[0][m][n];
    string respu(n,'0');
    for(int i=1;i<=n;i++){
        ll lof=0,los=0;
        for(int j=0;j<=m;j++){
            lof=max(lof,dp[0][j][i-1]+dp[1][m-j][i+1]);
            if(j<=m-nums[i].first)los=max(los,dp[0][j][i-1]+dp[1][m-nums[i].first-j][i+1]);
        }
        if(lof==res && los==res-nums[i].second)respu[i-1]='B';
        else if(los==res-nums[i].second)respu[i-1]='A';
        else respu[i-1]='C';
    }
    cout << respu;
}