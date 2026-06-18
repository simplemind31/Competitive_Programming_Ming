#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,n,m,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<pair<int,int>> graph[2][n];
    while(m--){
        cin >> a >> b >> c;
        graph[0][--a].push_back({--b,c});
        graph[1][b].push_back({a,c});
    }
    ll dist[2][n];
    fill(&dist[0][0],&dist[0][0]+2*n,1e18);
    dist[0][0]=0;
    dist[1][n-1]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> dij[2];
    dij[0].push({0,0});
    dij[1].push({0,n-1});
    for(int k=0;k<2;k++){
        while(!dij[k].empty()){
            int node=dij[k].top().second;
            int di=dij[k].top().first;
            dij[k].pop();
            if(dist[k][node]<di)continue;
            for(auto u:graph[k][node]){
                if(dist[k][u.first]>dist[k][node]+u.second){
                    dist[k][u.first]=dist[k][node]+u.second;
                    dij[k].push({dist[k][u.first],u.first});
                }
            }
        }
    }
    ll mini=1e18;
    for(int i=0;i<n;i++){
        for(auto u:graph[0][i]){
            if(u.second/2+dist[0][i]+dist[1][u.first]<mini){
                mini=u.second/2+dist[0][i]+dist[1][u.first];  
            }
        }
    }
    cout << mini;
}