#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int B;
    vector<int> present,future;
    vector<vector<int>> g;
    // returns{dp0,dp1,subtreeSize}
    pair<vector<int>,vector<int>> dfs(int u){
        int cost=present[u];
        int dCost=cost/2;
        vector<int> dp0(B+1,0),dp1(B+1,0);
        vector<int> subProfit0(B+1,0),subProfit1(B+1,0);
        for(int v:g[u]){
            pair<vector<int>,vector<int>> temp=dfs(v);
            vector<int> subDp0=temp.first;
            vector<int> subDp1=temp.second;
            for(int i=B;i>=0;i--){
                for(int sub=0;sub<=i;sub++){
                    subProfit0[i]=max(subProfit0[i],subProfit0[i-sub]+subDp0[sub]);
                    subProfit1[i]=max(subProfit1[i],subProfit1[i-sub]+subDp1[sub]);
                }
            }
        }
        for(int i=0;i<=B;i++){
            dp0[i]=dp1[i]=subProfit0[i];
            // must purchase parent → discount available
            if(i>=dCost){
                dp1[i]=max(dp1[i],subProfit1[i-dCost]+future[u]-dCost);
            }
            // parent not purchased → no discount
            if(i>=cost){
                dp0[i]=max(dp0[i],subProfit1[i-cost]+future[u]-cost);
            }
        }
        return{dp0,dp1};
    }
    int maxProfit(int n,vector<int>& present_,vector<int>& future_,vector<vector<int>>& hierarchy,int budget){
        B=budget;
        present=present_;
        future=future_;
        g.assign(n,{});
        for(auto& e:hierarchy){
            g[e[0]-1].push_back(e[1]-1);
        }
        pair<vector<int>,vector<int>> temp=dfs(0);
        vector<int> dp0=temp.first;
        return dp0[budget];
    }
};
