#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,a,b,c;
vector<vector<bool>> visited;
vector<vector<ll>> dist;
vector<vector<pair<int,ll>>> graph;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    dist.assign(n,vector<ll>(k,1e18));
    graph.resize(n);
    visited.assign(n,vector<bool>(k));
    while(m--){
        cin >> a >> b >> c;
        graph[--a].push_back({--b,c});
    }
    priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>> dij;
    dist[0][0]=0;
    dij.push({0,{0,0}});
    while(!dij.empty()){
        pair<int,int> top=dij.top().second;
        dij.pop();
        if(visited[top.first][top.second])continue;
        visited[top.first][top.second]=true;
        for(auto u:graph[top.first]){
            // actualizar la peor distancia
            ll maxipos=0;
            for(int j=1;j<k;j++)if(dist[u.first][j]>dist[u.first][maxipos])maxipos=j;
            if(dist[u.first][maxipos]>=dist[top.first][top.second]+u.second){
                dist[u.first][maxipos]=dist[top.first][top.second]+u.second;
                dij.push({dist[u.first][maxipos],{u.first,maxipos}});
            }
        }
    }
    vector<ll> res;
    for(auto u:dist[n-1])res.push_back(u);
    sort(res.begin(),res.end());
    for(auto u:res)cout << u << ' ';
}