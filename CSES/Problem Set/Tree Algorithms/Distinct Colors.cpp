#include <bits/stdc++.h>
using namespace std;
int n,color[200000],a,b,res[200000];
vector<int> graph[200000];
map<int,bool> mapa[200000];
void dfs(int node,int ante){
    mapa[node][color[node]]=true;
    for(auto u:graph[node]){
        if(u==ante)continue;
        dfs(u,node);
        if(mapa[node].size()<mapa[u].size())mapa[node].swap(mapa[u]);
        for(auto v:mapa[u])mapa[node][v.first]=1;
    }
    res[node]=mapa[node].size();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> color[i];
        color[i]--;
    }
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    for(int i=0;i<n;i++)cout << res[i] << ' ';
}