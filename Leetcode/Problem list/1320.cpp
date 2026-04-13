#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
class Solution {
public:
    int dist(char a,char b){
        if(a==' ' || b==' ')return 0;
        int ya=(a-65)/6,xa=(a-65)%6;
        int yb=(b-65)/6,xb=(b-65)%6;
        return abs(ya-yb)+abs(xa-xb);
    }
    int minimumDistance(string word){
        word.insert(0,1,' ');
        int n=word.size(),res=1e9;
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        // dp[i][j], finger iz=i finger de=j;
        dp[0][0]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // el iz avanza
                int maxi=max(i,j)+1;
                if(maxi==n)continue;
                dp[maxi][j]=min(dp[maxi][j],dp[i][j]+dist(word[i],word[maxi]));
                dp[i][maxi]=min(dp[i][maxi],dp[i][j]+dist(word[j],word[maxi]));
            }
        }
        for(int j=0;j<n;j++)res=min(res,dp[n-1][j]);
        return res;
    }
};