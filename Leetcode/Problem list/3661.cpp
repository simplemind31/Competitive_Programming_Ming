#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls){
        int n=robots.size();
        sort(ALL(walls));
        vector<pair<int,int>> r(n);
        for(int i=0;i<n;i++)r[i]={robots[i],distance[i]};
        r.push_back({1000000007,0});
        r.push_back({-1000000007,0});
        sort(ALL(r));
        vector<vector<int>> dp(n+2,vector<int>(2));
        for(int i=1;i<=n;i++){
            dp[i][1]=max(dp[i-1][0],dp[i-1][1])+upper_bound(ALL(walls),min(r[i].first+r[i].second,r[i+1].first-1))-lower_bound(ALL(walls),r[i].first);
            dp[i][0]=max(dp[i-1][0]+(int)(upper_bound(ALL(walls),r[i].first)-lower_bound(ALL(walls),max(r[i].first-r[i].second,r[i-1].first+1))),dp[i-1][1]+(int)(upper_bound(ALL(walls),r[i].first)-lower_bound(ALL(walls),max(min(r[i-1].first+r[i-1].second,r[i].first-1)+1,r[i].first-r[i].second))));
        }
        return max(dp[n][0],dp[n][1]);
    }
};