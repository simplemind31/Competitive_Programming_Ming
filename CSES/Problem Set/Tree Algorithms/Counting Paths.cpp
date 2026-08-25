#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,a,b,tiempo;
vector<vector<int>> graph;
vector<int> bigchild,pad,head,tin,depth,psum;
int dfs(int node){
    int tam=1,maxitam=0;
    bigchild[node]=-1;
    for(auto u:graph[node]){
        if(u==pad[node])continue;
        pad[u]=node,depth[u]=depth[node]+1;
        int tamu=dfs(u);
        if(tamu>maxitam)bigchild[node]=u,maxitam=tamu;
        tam+=tamu;
    }
    return tam;
}
void descompose(int node,int h){
    tin[node]=tiempo++,head[node]=h;
    if(bigchild[node]!=-1)descompose(bigchild[node],h);
    for(auto u:graph[node])if(u!=pad[node] && u!=bigchild[node])descompose(u,u);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    graph.resize(n);
    bigchild.resize(n);
    depth=tin=pad=head=bigchild;
    psum.resize(n+2);
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0);
    descompose(0,0);
    while(q--){
        cin >> a >> b;
        a--;b--;
        for(;head[a]!=head[b];b=pad[head[b]]){
            if(depth[head[a]]>depth[head[b]])swap(a,b);
            psum[tin[head[b]]+1]++;
            psum[tin[b]+2]--;
        }
        if(depth[a]>depth[b])swap(a,b);
        psum[tin[a]+1]++;
        psum[tin[b]+2]--;
    }
    for(int i=1;i<=n;i++)psum[i]+=psum[i-1];
    for(int i=0;i<n;i++)cout << psum[tin[i]+1] << ' ';
}