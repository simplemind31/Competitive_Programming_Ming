#include <bits/stdc++.h>
using namespace std;
int n,MOD,a,b;
vector<int> dp,res;
vector<vector<int>> graph;
vector<vector<int>> mult,mult1;
// dp[i]= si i es el mas alto que está de negro
// dp[i]=para cada hijo elijo o no
void dfs(int node,int ante){
    dp[node]=1;
    for(auto u:graph[node]){
        if(u==ante)continue;
        dfs(u,node);
        dp[node]=1ll*dp[node]*(dp[u]+1)%MOD;
    }
}
void reroot(int node,int ante){
    res[node]=dp[node];
    mult[node].resize(graph[node].size());
    mult1[node].resize(graph[node].size());
    mult[node][0]=dp[graph[node][0]]+1;
    mult1[node].back()=dp[graph[node].back()]+1;
    for(int i=1;i<graph[node].size();i++){
        mult[node][i]=1ll*mult[node][i-1]*(dp[graph[node][i]]+1)%MOD;
    }
    for(int i=graph[node].size()-2;i>=0;i--){
        mult1[node][i]=1ll*mult1[node][i+1]*(dp[graph[node][i]]+1)%MOD;
    }
    for(int i=0;i<graph[node].size();i++){
        if(graph[node][i]==ante)continue;
        // omito graph[node][i];
        int antenode=dp[node],antehi=dp[graph[node][i]];
        dp[node]=1ll*((i-1>=0)?mult[node][i-1]:1)*((i+1<graph[node].size())?mult1[node][i+1]:1)%MOD;
        dp[graph[node][i]]=1ll*dp[graph[node][i]]*(dp[node]+1)%MOD;
        reroot(graph[node][i],node);
        dp[graph[node][i]]=antenode;
        dp[node]=antehi;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> MOD;
    dp.resize(n);
    graph.resize(n);
    mult.resize(n);
    mult1.resize(n);
    res.resize(n);
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    if(n==1){
        cout << 1;
        return 0;
    }
    dfs(0,-1);
    reroot(0,-1);
    for(int i=0;i<n;i++)cout << res[i] << '\n';
}