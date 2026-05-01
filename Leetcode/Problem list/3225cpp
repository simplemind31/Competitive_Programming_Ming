#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution{
public:
    long long maximumScore(vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        ll supermaxi=0;
        vector<vector<ll>> psum(n+2,vector<ll>(m+2));
        vector<vector<vector<ll>>> dp(n+2,vector<vector<ll>>(m+2,vector<ll>(2)));
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)psum[i][j]=psum[i-1][j]+grid[i-1][j-1];
        for(int j=1;j<=m;j++){
            for(int i=0;i<=n;i++){
                for(int k=0;k<=n;k++){
                    if(k>=i){
                        dp[i][j][1]=max(dp[i][j][1],dp[k][j-1][1]-psum[i][j]+psum[i][j+1]);
                        dp[i][j][1]=max(dp[i][j][1],dp[k][j-1][0]-psum[i][j]+psum[i][j+1]);
                        if(j-2>=0)dp[i][j][0]=max(dp[i][j][0],max(dp[k][j-2][1],dp[k][j-2][0])+psum[i][j+1]);
                    }else{
                        dp[i][j][0]=max(dp[i][j][0],dp[k][j-1][0]-psum[k][j]+psum[i][j+1]+(psum[i][j-1]-psum[k][j-1]));
                        if(j-2>=0)dp[i][j][0]=max(dp[i][j][0],max(dp[k][j-2][1],dp[k][j-2][0])+psum[i][j+1]+(psum[i][j-1]-psum[k][j-1]));
                    }
                }
                supermaxi=max(supermaxi,max(dp[i][j][0],dp[i][j][1]));
            }
        }
        return supermaxi;
    }
};