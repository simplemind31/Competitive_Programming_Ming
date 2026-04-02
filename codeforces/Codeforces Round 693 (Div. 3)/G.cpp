#include <bits/stdc++.h>
using namespace std;
int t,n,m,a,b;
vector<bool> visited;
vector<int> dist,res;
vector<vector<int>> graph;
int dfs(int node){
    if(visited[node])return res[node];
    visited[node]=true;
    for(auto u:graph[node]){
        if(dist[u]>dist[node])res[node]=min(res[node],dfs(u));
    }
    return res[node];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        visited.clear();
        visited.shrink_to_fit();
        visited.resize(n);
        graph.clear();
        graph.shrink_to_fit();
        dist.clear();
        dist.shrink_to_fit();
        dist.assign(n,1e9);
        graph.resize(n);
        while(m--){
            cin >> a >> b;
            graph[--a].push_back(--b);
        }
        dist[0]=0;
        queue<int> bfs;
        bfs.push(0);
        while(!bfs.empty()){
            int top=bfs.front();
            bfs.pop();
            for(auto u:graph[top]){
                if(dist[u]==1e9){
                    dist[u]=dist[top]+1;
                    bfs.push(u);
                }
            }
        }
        res=dist;
        for(int i=0;i<n;i++){
            for(auto u:graph[i])res[i]=min(res[i],dist[u]);
        }
        for(int i=0;i<n;i++)cout << dfs(i) << ' ';
        cout << '\n';
    }
}