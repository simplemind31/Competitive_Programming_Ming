#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int n,m;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid,int k){
        n=grid.size();
        m=grid[0].size();
        int dp[n][m][k];
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int l=0;l<k;l++)dp[i][j][l]=0;
        dp[0][0][grid[0][0]%k]=1;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int l=0;l<k;l++){
            if(j+1<m)dp[i][j+1][(l+grid[i][j+1])%k]=(dp[i][j+1][(l+grid[i][j+1])%k]+dp[i][j][l])%MOD;
            if(i+1<n)dp[i+1][j][(l+grid[i+1][j])%k]=(dp[i+1][j][(l+grid[i+1][j])%k]+dp[i][j][l])%MOD;
        }
        return dp[n-1][m-1][0];
    }
};