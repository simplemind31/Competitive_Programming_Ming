#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a,b,c,con;
vector<vector<pair<int,ll>>> graph;
vector<vector<int>> rev;
vector<ll> dist;
vector<bool> posi;
void dfs(int node){
    for(auto u:rev[node]){
        if(posi[u])continue;
        posi[u]=1;
        dfs(u);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    graph.resize(n);
    dist.assign(n,-1e18);
    posi.resize(n);
    rev.resize(n);
    while(m--){
        cin >> a >> b >> c;
        graph[--a].push_back({--b,c});
        rev[b].push_back(a);
    }
    posi[n-1]=1;
    dfs(n-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<graph[i].size();j++){
            if(!posi[graph[i][j].first]){
                graph[i].erase(graph[i].begin()+j);
                j--;
            }
        }
    }
    queue<int> mejora;
    dist[0]=0;
    mejora.push(0);
    while(!mejora.empty() && ++con<1e6){
        int top=mejora.front();
        mejora.pop();
        for(auto u:graph[top]){
            if(dist[u.first]<dist[top]+u.second){
                dist[u.first]=dist[top]+u.second;
                mejora.push(u.first);
            }
        }
    }
    if(con>=1e6)cout << -1;
    else cout << dist[n-1];
}