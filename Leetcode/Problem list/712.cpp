#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeleteSum(string s1, string s2){
        int n=s1.size(),m=s2.size(),res=(n+m)*150;
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        vector<int> psum1(n+2),psum2(m+2),ssum1(n+2),ssum2(m+2);
        for(int i=1;i<=n;i++)psum1[i]=psum1[i-1]+s1[i-1];
        for(int j=1;j<=m;j++)psum2[j]=psum2[j-1]+s2[j-1];
        for(int i=n;i>0;i--)ssum1[i]=ssum1[i+1]+s1[i-1];
        for(int j=m;j>0;j--)ssum2[j]=ssum2[j+1]+s2[j-1];
        for(int i=1;i<=n;i++)dp[i][0]=psum1[i];
        for(int j=1;j<=m;j++)dp[0][j]=psum2[j];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=min(dp[i-1][j]+s1[i-1],dp[i][j-1]+s2[j-1]);
                if(s1[i-1]==s2[j-1])dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                res=min(res,dp[i][j]+ssum1[i+1]+ssum2[j+1]);
            }
        }
        return res;
    }
};