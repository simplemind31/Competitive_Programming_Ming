#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,maxi=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums1[n+1];
    nums1[0]=0;
    for(int i=1;i<=n;i++)cin >> nums1[i];
    cin >> m;
    int nums2[m+1];
    nums2[0]=0;
    for(int i=1;i<=m;i++)cin >> nums2[i];
    int dp[n+1][m+1],pad[n+1][m+1];// maximo si considero los primero i del nums1, y termino en el j del nums2
    memset(dp,0,sizeof(dp));
    memset(pad,0,sizeof(pad));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            pad[i][j]=pad[i-1][j];
            if(nums1[i]==nums2[j]){
                dp[i][j]=max(dp[i][j],1);
                for(int k=j-1;k>0;k--){
                    if(nums2[j]>nums2[k]){
                        if(dp[i-1][k]+1>dp[i][j]){
                            dp[i][j]=dp[i-1][k]+1;
                            pad[i][j]=k;
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(dp[n][maxi]<dp[n][i])maxi=i;
    }
    cout << dp[n][maxi] << '\n';
    if(dp[n][maxi]==0)return 0;
    int now=maxi,now2=n;
    vector<int> res;
    while(now){
        res.push_back(nums2[now]);
        now=pad[now2][now];
        now2--;
    }
    reverse(ALL(res));
    for(auto u:res)cout << u << ' ';
}