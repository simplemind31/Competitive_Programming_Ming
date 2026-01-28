#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(vector<vector<int>>& grid,int k){
        grid[0][0]=0;
        int n=grid.size(),m=grid[0].size();
        int dp[n+1][m+1][k+1];
        // minima cantidad para llegar a i,j con k transport
        for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)for(int l=0;l<=k;l++)dp[i][j][l]=1e9;
        vector<pair<int,int>> nums[10001]; 
        dp[0][1][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //if(i==1 && j==1)continue;
                dp[i][j][0]=min(dp[i-1][j][0],dp[i][j-1][0])+grid[i-1][j-1];
                nums[grid[i-1][j-1]].push_back({i,j});
            }
        }
        for(int l=1;l<=k;l++){
            int mini=1e9;
            for(int ii=10000;ii>=0;ii--){
                for(auto p:nums[ii]){
                    mini=min(mini,dp[p.first][p.second][l-1]);
                }
                for(auto p:nums[ii]){
                    dp[p.first][p.second][l]=mini;
                }
            }
        }
        return dp[n][m][k];
    }
};