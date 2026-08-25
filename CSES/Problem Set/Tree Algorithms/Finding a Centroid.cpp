#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b;
vector<vector<int>> graph;
vector<int> tam;
void dfs(int node,int pad){
    tam[node]=1;
    for(auto u:graph[node]){
        if(u==pad)continue;
        dfs(u,node);
        tam[node]+=tam[u];
    }
}
int find(int node,int pad){
    for(auto u:graph[node]){
        if(u==pad)continue;
        if(tam[u]>n/2)return find(u,node);
    }
    return node;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    graph.resize(n);
    tam.resize(n);
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    cout << find(0,-1)+1;
}