#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a,b,tiempo;
vector<int> tin,low;
vector<vector<int>> graph,H;
vector<int> s;
vector<vector<int>> color;
vector<bool> ap;
vector<bool> visited;
int k;
ll res;
void dfs(int node,int pad){
    //cout << node << ' ';
    low[node]=tin[node]=++tiempo;
    s.push_back(node);
    for(auto u:graph[node]){
        if(!tin[u]){
            dfs(u,node);
            low[node]=min(low[node],low[u]);
            if(low[u]==tin[node]){
                // es un articulacion
                ap[node]=true;
                for(int x=s.back();x!=u;){
                    H[x].push_back(k);
                    H[k].push_back(x);
                    color[x].push_back(k);
                    s.pop_back();
                    x=s.back();
                }
                color[u].push_back(k);
                H[u].push_back(k);
                H[k].push_back(u);
                s.pop_back();
                color[node].push_back(k);
                H[node].push_back(k);
                H[k].push_back(node);
                k++;
            }
        }
        low[node]=min(low[node],tin[u]);
    }
}
ll dfs2(int node,int pad){
    ll tam=0;
    for(auto u:H[node]){
        if(u==pad)continue;
        tam+=dfs2(u,node);
    }
    ll otro=n-tam-1;
    if(ap[node]){
        cout << node << ' ' << tam << ' ' << otro << '\n';
        res+=2*tam*otro;
    }
    if(node>=n){

    }
    if(node<n)tam++;
    return tam;
}
ll subtam;
void dfs4(int node,int pad){
    visited[node]=true;
    subtam++;
    for(auto u:graph[node]){
        if(visited[u])continue;
        dfs4(u,node);
    }
}
ll dfs3(int node,int pad){
    ll tam=0;
    for(auto u:graph[node]){
        if(u==pad)continue;
        tam+=dfs3(u,node);
    }
    ll otro=subtam-tam-1;
    res+=2*tam*otro;
    tam++;
    return tam;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    graph.resize(2*n);
    tin.resize(2*n);
    low.resize(2*n);
    color.resize(2*n);
    ap.resize(2*n);
    H.resize(2*n);
    visited.resize(2*n);
    if(m>=n)return 0;
    while(m--){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    k=n;
    for(int i=0;i<n;i++){
        if(visited[i])continue;
        subtam=0;
        dfs4(i,-1);
        dfs3(i,-1);
        //dfs(0,-1);
        //for(int i=0;i<n;i++)if(ap[i])cout << i << '\n';
        /*for(int i=0;i<n;i++){
            cout << i << ": ";
            for(auto u:color[i]){
                cout << u << ' ';
            }
            cout << '\n';
        }*/
        //dfs2(0,-1);
    }
    cout << res;
}