#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b,m,c;
vector<vector<pair<ll,ll>>> g,graph;
vector<ll> tam,res[2],supermegares;
vector<bool> necesa;
void quitarpadre(int node,int ante=-1){
    for(auto u:g[node]){
        if(u.first==ante)continue;
        graph[node].push_back(u);
        quitarpadre(u.first,node);
    }
}
void dfs(ll node){
    tam[node]=res[0][node]=res[1][node]=0;
    if(necesa[node])tam[node]++;
    if(graph[node].size()==0)return;
    ll mini=0;
    for(auto u:graph[node]){
        dfs(u.first);
        tam[node]+=tam[u.first];
        if(tam[u.first]){
            res[1][node]+=res[1][u.first]+2*u.second;
            mini=min(mini,-(res[1][u.first]+2*u.second)+(res[0][u.first]+u.second));
        }
    }
    //cout << node << ' ' << tamsub << '\n';
    // no vuelvo? en cual me quedo?-> min(volver de todos menos uno)
    res[0][node]=res[1][node]-mini;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    supermegares.resize(n);
    g.resize(n);
    graph.resize(n);
    tam.resize(n);
    res[0].resize(n);
    res[1].resize(n);
    // si vuelvo->1, si no vuelvo->0
    necesa.resize(n);
    for(ll i=1;i<n;i++){
        cin >> a >> b >> c;
        g[--a].push_back({--b,c});
        g[b].push_back({a,c});
    }
    while(m--){
        cin >> a;
        necesa[--a]=true;
    }
    quitarpadre(0);
    dfs(0);
    for(int i=0;i<n;i++){
        cout << tam[i] << ' ' << res[0][node] << ' ' << res[1][node];
    }
    cout << min(res[0][i],res[1][i]) << '\n';
    /*for(int i=0;i<n;i++){
        graph.clear();
        graph.resize(n);
        quitarpadre(i);
        dfs(i);
        //reroot(0);
        cout << min(res[0][i],res[1][i]) << '\n';
    }*/
    //for(int i=0;i<n;i++)cout << supermegares[i] << '\n';
}
