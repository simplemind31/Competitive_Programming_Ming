#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int p,c,a,b,tiempo,tin[100],low[100];
bitset<100> visited;
vector<vector<int>> graph;
bool dfs(int node,int ante){
    tin[node]=low[node]=++tiempo;
    visited[node]=true;
    for(auto u:graph[node]){
        if(u==ante)continue;
        if(visited[u])low[node]=min(low[node],tin[u]);
        else{
            if(dfs(u,node))return true;
            low[node]=min(low[node],low[u]);
            if(low[u]>tin[node])return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(true){
        cin >> p >> c;
        if(!p && !c)break;
        graph.clear();
        graph.resize(p);
        visited=0;
        tiempo=0;
        while(c--){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bool xd=dfs(0,-1);
        for(int i=1;i<p && !xd;i++)if(!visited[i])xd=true;
        cout << (xd?"Yes\n":"No\n");
    }
}