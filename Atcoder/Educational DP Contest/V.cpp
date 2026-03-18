#include <bits/stdc++.h>
using namespace std;
int n,MOD,res[100000],a,b,dp[100000],psum[100000];
// dp[i]= si i es el mas alto que está de negro
// dp[i]=para cada hijo elijo o no
// psum[i]= si el subtree esta negro
vector<int> graph[100000];
void dfs(int node,int ante){
    for(auto u:graph[node]){
        if(u==ante)continue;
        dfs(u,node);
        //psum[node]+=psum[u];
        dp[node]=2*dp[node]+dp[u];
    }
    dp[node]++;
    //psum[node]+=dp[node];
    //cout << node << ' ' << dp[node] << '\n';
}
void reroot(int node,int ante){
    for(auto u:graph[node]){
        if(u==ante)continue;
        
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> MOD;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    reroot(0,-1);
}