#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("nocross.in","r",stdin);
    freopen("nocross.out","w",stdout);
    cin >> n;
    int nums1[n+1]={0},nums2[n+1]={0},dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)cin >> nums1[i];
    for(int i=1;i<=n;i++)cin >> nums2[i];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i)dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(j)dp[i][j]=max(dp[i][j],dp[i][j-1]);
            if(i&&j)if(abs(nums1[i]-nums2[j])<=4)dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    cout << dp[n][n];
}