#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a,b;
vector<pair<ll,ll>> rango;
vector<vector<int>> graph;
vector<vector<ll>> dp;
void dfs(int node,int pad){
    for(auto u:graph[node]){
        if(u==pad)continue;
        dfs(u,node);
        dp[node][0]+=max(abs(rango[node].first-rango[u].first)+dp[u][0],abs(rango[node].first-rango[u].second)+dp[u][1]);
        dp[node][1]+=max(abs(rango[node].second-rango[u].first)+dp[u][0],abs(rango[node].second-rango[u].second)+dp[u][1]);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // o usar l o usar r;
    cin >> t;
    while(t--){
        cin >> n;
        rango.clear();
        rango.resize(n);
        graph.clear();
        graph.resize(n);
        dp.clear();
        dp.assign(n,vector<ll>(2));
        for(int i=0;i<n;i++)cin >> rango[i].first >> rango[i].second;
        for(int i=1;i<n;i++){
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }
        dfs(0,-1);
        cout << max(dp[0][0],dp[0][1]) << '\n';
    }
}