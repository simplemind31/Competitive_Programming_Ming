#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
#define MOD 998244353
using namespace std;
typedef long long ll;
int n,k,maxi;
ll a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    pair<int,int> nums[n+1];
    for(int i=1;i<=n;i++){
        cin >> a;
        for(;a%2==0;a/=2)nums[i].first++;
        for(;a%5==0;a/=5)nums[i].second++;
    }
    int dp[n*64+1][k+1];// maxima cantidad de 5 si tengo i 2s y use k subset
    for(int i=0;i<=n*64;i++)for(int j=0;j<=k;j++)dp[i][j]=-1e9;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int l=64*n;l>=nums[i].first;l--){
            for(int j=k;j>=1;j--)dp[l][j]=max(dp[l][j],dp[l-nums[i].first][j-1]+nums[i].second);
            maxi=max(maxi,min(l,dp[l][k]));
        }
    }
    cout << maxi;
}