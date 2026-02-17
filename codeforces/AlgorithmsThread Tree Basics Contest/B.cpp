#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,maxi;
vector<bool> pertenece;
vector<int> len;
vector<vector<int>> graph;
void dfs(int node,int ante){
    if(len[node]>len[maxi])maxi=node;
    for(auto u:graph[node]){
        if(u==ante)continue;
        len[u]=len[node]+1;
        dfs(u,node);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    graph.resize(n);
    len.resize(n);
    pertenece.resize(n);
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    len[maxi]=0;
    dfs(maxi,-1);
    for(int i=0;i<n;i++)if(len[i]==len[maxi])pertenece[i]=true;
    len[maxi]=0;
    dfs(maxi,-1);
    for(int i=0;i<n;i++)if(len[i]==len[maxi])pertenece[i]=true;
    for(int i=0;i<n;i++)cout << len[maxi]+pertenece[i] << '\n';
}