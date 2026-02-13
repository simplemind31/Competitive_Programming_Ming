#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b;
ll res;
vector<int> val;
vector<ll> longi,tam;
vector<vector<int>> graph;
void dfs(int node,int ante){
    tam[node]=val[node];
    for(auto u:graph[node]){
        if(u==ante)continue;
        dfs(u,node);
        tam[node]+=tam[u];
        longi[node]+=longi[u]+tam[u];
    }
}
void reroot(int node,int ante){
    res=max(res,longi[node]);
    for(auto u:graph[node]){
        if(u==ante)continue;
        tam[node]-=tam[u];
        longi[node]-=tam[u]+longi[u];
        tam[u]+=tam[node];
        longi[u]+=longi[node]+tam[node];
        reroot(u,node);
        tam[u]-=tam[node];
        longi[u]-=longi[node]+tam[node];
        tam[node]+=tam[u];
        longi[node]+=tam[u]+longi[u];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    val.resize(n);
    tam.resize(n);
    longi.resize(n);
    graph.resize(n);
    for(int i=0;i<n;i++)cin >> val[i];
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    reroot(0,-1);
    cout << res;
}