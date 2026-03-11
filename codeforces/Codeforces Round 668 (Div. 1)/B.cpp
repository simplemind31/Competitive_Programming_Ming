#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n,a,b,da,db,x,y,pos;
vector<vector<int>> graph;
vector<int> dist;
void dfs(int node,int ante){
    if(dist[node]>dist[pos])pos=node;
    for(auto u:graph[node]){
        if(u==ante)continue;
        dist[u]=dist[node]+1;
        dfs(u,node);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> a >> b >> da >> db;
        graph.clear();
        graph.resize(n);
        dist.clear();
        dist.resize(n);
        pos=0;
        a--;b--;
        for(int i=1;i<n;i++){
            cin >> x >> y;
            graph[--x].push_back(--y);
            graph[y].push_back(x);
        }
        if(2*da+1>db){
            cout << "Alice\n";
            continue;
        }
        // su distancia es <=da?
        dfs(a,-1);
        if(dist[b]<=da){
            cout << "Alice\n";
            continue;
        }
        dist.clear();
        dist.resize(n);
        dfs(pos,-1);
        // diametro de <=2*da?
        if(dist[pos]<=2*da)cout << "Alice\n";
        else cout << "Bob\n";
    }
}