#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,a,b,c;
vector<vector<vector<int>>> graph;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // simepre tomar el minimo camino? bfs?
    // es armar un numero
    // si originalmente 1metro=1s
    // si tomo uno 1 metro =10s
    // si tomo 2 1 metro=100
    cin >> n >> m;
    graph.assign(n,vector<vector<int>>(10));
    while(m--){
        cin >> a >> b >> c;
        graph[a][c].push_back(b);
        graph[b][c].push_back(a);
    }
    vector<int> dist(n,1e9);
    vector<pair<int,int>> pad(n,{-1,-1});
    dist[n-1]=0;
    queue<int> bfs2;
    vector<pair<int,int>> bfs;
    bfs2.push(n-1);
    int posicion=0;
    // procesar en grupos
    // los que tienen igual en grupos
    // si de x al y tiene igual rango, los proceso al mismo tiempo
    while(!bfs2.empty()){
        int top=bfs2.front();
        bfs2.pop();
        bfs.push_back({top,bfs.size()});
        for(auto u:graph[top][0]){
            if(dist[u]!=1e9)continue;
            dist[u]=dist[top]+1;
            pad[u]={top,0};
            bfs2.push(u);
        }
    }
    bfs[0].second=bfs.size()-1;
    while(posicion<bfs.size()){
        // procesar este rango al mismo tiempo
        for(int i=0;i<10;i++){
            int anteposicion=bfs.size();
            for(int j=posicion;j<=bfs[posicion].second;j++){
                for(auto u:graph[bfs[j].first][i]){
                    if(pad[u]!=make_pair(-1,-1))continue;
                    pad[u]={bfs[j].first,i};
                    bfs.push_back({u,bfs.size()});
                }
            }
            if(anteposicion!=bfs.size())bfs[anteposicion].second=bfs.size()-1;
        }
        posicion=bfs[posicion].second+1;
    }
    vector<pair<int,int>> res;
    int now=0;
    while(now!=n-1){
        res.push_back(pad[now]);
        now=pad[now].first;
    }
    string super="";
    for(auto u:res)super.push_back(u.second+'0');
    while(!super.empty() && super.back()=='0')super.pop_back();
    if(super.empty())super.push_back('0');
    reverse(ALL(super));
    cout << super << '\n' << res.size()+1 << "\n0 ";
    for(auto u:res)cout << u.first <<' ';
}