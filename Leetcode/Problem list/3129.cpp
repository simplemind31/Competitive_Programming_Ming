#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
class Solution{
public:
    int numberOfStableArrays(int zero, int one, int limit){
        vector<vector<ll>> dp[2];
        dp[0].assign(zero+1,vector<ll>(one+1));
        dp[1].assign(zero+1,vector<ll>(one+1));
        for(int i=0;i<=min(zero,limit);i++)dp[0][i][0]=1;
        for(int i=0;i<=min(one,limit);i++)dp[1][0][i]=1;
        for(int i=1;i<=zero;i++){
            for(int j=1;j<=one;j++){
                dp[0][i][j]+=(dp[1][i-1][j]+dp[0][i-1][j])%MOD;
                if(i>limit){
                    dp[0][i][j]=(dp[0][i][j]-dp[1][i-limit-1][j]+MOD)%MOD;
                }
                dp[1][i][j]+=(dp[0][i][j-1]+dp[1][i][j-1])%MOD;
                if(j>limit){
                    dp[1][i][j]=(dp[1][i][j]-dp[0][i][j-limit-1]+MOD)%MOD;
                }
            }
        }
        return (dp[0][zero][one]+dp[1][zero][one])%MOD;
    }
};