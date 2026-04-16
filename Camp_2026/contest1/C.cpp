#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,maxi,a,b;
vector<vector<int>> graph;
vector<int> dist;
void dfs(int node,int ante=-1){
    if(dist[maxi]<dist[node])maxi=node;
    for(auto u:graph[node]){
        if(u==ante)continue;
        dist[u]=dist[node]+1;
        dfs(u,node);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    graph.resize(n);
    dist.resize(n);
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0);
    dist[maxi]=0;
    dfs(maxi);
    cout << dist[maxi];
}