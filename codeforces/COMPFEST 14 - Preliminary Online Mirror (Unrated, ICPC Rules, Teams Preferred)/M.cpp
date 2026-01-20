#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool visited[200000];
int n,m,a,b,c;
ll dist[200000];
vector<pair<int,int>> graph[200000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> c;
        graph[--a].push_back({--b,c});
        graph[b+100000].push_back({a+100000,c});
    }
    for(int i=0;i<n;i++)graph[i].push_back({i+100000,0});
    for(int i=0;i<200000;i++)dist[i]=1e18;
    dist[0]=0;
    priority_queue<pair<ll,int>> dij;
    dij.push({0,0});
    while(!dij.empty()){
        pair<ll,int> top=dij.top();
        dij.pop();
        if(visited[top.second])continue;
        visited[top.second]=true;
        for(auto u:graph[top.second]){
            if(dist[u.first]>dist[top.second]+u.second){
                dist[u.first]=dist[top.second]+u.second;
                dij.push({-dist[u.first],u.first});
            }
        }
    }
    for(int i=1;i<n;i++){
        if(dist[i+100000]==1e18)cout << "-1 ";
        else cout << dist[i+100000] << ' ';
    }
}