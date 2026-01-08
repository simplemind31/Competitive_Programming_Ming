#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
class Solution {
public:
    int mini,n,m,mini1,mini2;
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        mini=-1e9;
        mini1=mini2=1e9;
        n=nums1.size();
        m=nums2.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)dp[i][j]=-1e9;
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int j=0;j<=m;j++)dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+nums1[i-1]*nums2[j-1]);
            }
        }
        if(dp[n][m]>0)return dp[n][m];
        for(int i=0;i<n;i++)mini1=min(mini1,abs(nums1[i]));
        for(int j=0;j<m;j++)mini2=min(mini2,abs(nums2[j]));
        return -mini1*mini2;
    }
};