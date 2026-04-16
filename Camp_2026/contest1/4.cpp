#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a,b,c;
vector<vector<pair<int,int>>> graph;
vector<ll> dist;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    graph.resize(n+1);
    while(m--){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    dist.assign(n+1,1e18);
    dist[0]=0;
    priority_queue<pair<ll,ll>> dij;
    dij.push({0,0});
    while(!dij.empty()){
        pair<int,int> top=dij.top();
        dij.pop();
        if(-top.first>dist[top.second])continue;
        for(auto u:graph[top.second]){
            if(dist[u.first]>dist[top.second]+u.second){
                dist[u.first]=dist[top.second]+u.second;
                dij.push({-dist[u.first],u.first});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dist[i]==1e18)dist[i]=-1;
        cout << dist[i] << ' ';
    }
}
