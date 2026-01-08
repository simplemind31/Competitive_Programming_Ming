#include <bits/stdc++.h>
using namespace std;
int n;
bool xd;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(k+1,vector<int>(2,xd=0)));
        for(int j=1;j<=k;j++){
            dp[0][j][1]=-prices[0];
        }
        for(int i=1;i<n;i++){
            xd=1-xd;
            for(int j=1;j<=k;j++){
                dp[xd][j][0]=max({dp[1-xd][j][1]+prices[i],dp[1-xd][j][0]});
                dp[xd][j][1]=max(dp[1-xd][j-1][0]-prices[i],dp[1-xd][j][1]);
            }
        }
        return dp[xd][k][0];
    }
};