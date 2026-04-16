#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b;
vector<vector<int>> graph;
vector<ll> tam,res,superres;
void dfs(int node,int ante=-1){
    tam[node]=1;
    for(auto u:graph[node]){
        if(u==ante)continue;
        dfs(u,node);
        tam[node]+=tam[u];
        res[node]+=res[u]+tam[u];
    }
}
void reroot(int node,int ante=-1){
    superres[node]=res[node];
    for(auto u:graph[node]){
        if(u==ante)continue;
        res[node]-=res[u]+tam[u];
        tam[node]-=tam[u];
        tam[u]+=tam[node];
        res[u]+=res[node]+tam[node];
        reroot(u,node);
        res[u]-=res[node]+tam[node];
        tam[u]-=tam[node];
        tam[node]+=tam[u];
        res[node]+=res[u]+tam[u];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    graph.resize(n);
    tam.resize(n);
    res.resize(n);
    superres.resize(n);
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0);
    reroot(0);
    for(int i=0;i<n;i++)cout << superres[i] << ' ';
}