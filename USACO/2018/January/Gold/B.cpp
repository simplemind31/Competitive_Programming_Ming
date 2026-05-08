#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a,b,res;
vector<int> dist;
vector<vector<int>> graph;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("atlarge.in","r",stdin);
    //freopen("atlarge.out","w",stdout);
    cin >> n >> k;
    graph.resize(n);
    dist.assign(n,1e9);
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    if(graph[--k].size()==1){
        cout << 1;
        return 0;
    }
    queue<pair<int,bool>> bfs;
    dist[k]=0;
    bfs.push({k,1});
    for(int i=0;i<n;i++){
        if(graph[i].size()==1){
            dist[i]=0;
            bfs.push({i,-1e9});
        }
    }
    while(!bfs.empty()){
        pair<int,int> top=bfs.front();
        bfs.pop();
        for(auto u:graph[top.first]){
            if(top.second && dist[u]<0){
                
            }
            if(dist[u]==1e9){
                pad[u]=top;
                dist[u]=dist[top]+1;
                bfs.push(u);
            }
        }
    }
    cout << res;
}