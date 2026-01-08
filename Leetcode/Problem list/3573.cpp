#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
bool xd;
class Solution {
public:
    ll maximumProfit(vector<int>& prices, int k){
        n=prices.size();
        vector<vector<vector<ll>>> dp(2,vector<vector<ll>>(k+1,vector<ll>(3,xd=0)));
        for(int j=1;j<=k;j++){
            dp[0][j][1]=prices[0];
            dp[0][j][2]=-prices[0];
        }
        for(int i=1;i<n;i++){
            xd=1-xd;
            for(int j=1;j<=k;j++){
                dp[xd][j][0]=max({dp[1-xd][j][1]-prices[i],dp[1-xd][j][2]+prices[i],dp[1-xd][j][0]});
                dp[xd][j][1]=max(dp[1-xd][j-1][0]+prices[i],dp[1-xd][j][1]);
                dp[xd][j][2]=max(dp[1-xd][j-1][0]-prices[i],dp[1-xd][j][2]);
            }
        }
        return dp[xd][k][0];
    }
};