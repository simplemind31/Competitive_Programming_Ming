#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<pair<int,int>>> graph;
vector<int> depth;
vector<int> bj[20],pad[20];
void dfs(int node){
    for(auto u:graph[node]){
        if(u.first==pad[0][node])continue;
        depth[u.first]=depth[node]+1;
        pad[0][u.first]=node;
        bj[0][u.first]=u.second;
        dfs(u.first);
    }
}
int camino(int a,int b){
    if(depth[a]>depth[b])swap(a,b);
    // subir b;
    int res=0,dis=depth[b]-depth[a];
    for(int i=19;i>=0;i--){
        if(dis&(1<<i)){
            res^=bj[i][b];
            b=pad[i][b];
        }
    }
    for(int i=19;i>=0;i--){
        if(pad[i][a]!=pad[i][b]){
            res^=bj[i][a];
            res^=bj[i][b];
            a=pad[i][a];
            b=pad[i][b];
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> orden(n-1);
    vector<pair<pair<int,int>,int>> edges(n-1);
    depth.resize(n);
    graph.resize(n);
    bj[0].resize(n);
    pad[0].resize(n);
    for(int i=0;i<n-1;i++){
        cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
        graph[--edges[i].first.first].push_back({--edges[i].first.second,edges[i].second});
        graph[edges[i].first.second].push_back({edges[i].first.first,edges[i].second});
    }
    dfs(0);
    for(int i=1;i<20;i++){
        bj[i].resize(n);
        pad[i].resize(n);
        for(int j=0;j<n;j++){
            bj[i][j]=bj[i-1][j]^bj[i-1][pad[i-1][j]];
            pad[i][j]=pad[i-1][pad[i-1][j]];
        }
    }
    for(int i=0;i<n-1;i++){
        cin >> orden[i];
        orden[i]--;
    }
}