#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid,int k){
        int n=grid.size(),m=grid[0].size(),maxi=-1e9;
        vector dp(n+1,vector(m+1,vector<int>(k+1,-1e9)));
        dp[1][1][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1 && j==1)continue;
                if(grid[i-1][j-1])for(int l=1;l<=k;l++)dp[i][j][l]=max(dp[i-1][j][l-1],dp[i][j-1][l-1])+grid[i-1][j-1];
                else for(int l=0;l<=k;l++)dp[i][j][l]=max(dp[i-1][j][l],dp[i][j-1][l]);
            }
        }
        for(int l=0;l<=k;l++)maxi=max(maxi,dp[n][m][l]);
        if(maxi<0)maxi=-1;
        return maxi;
    }
};