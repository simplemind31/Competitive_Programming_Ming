#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,a,b;
ll maxi;
vector<bool> posi;
vector<vector<int>> graph;
vector<int> degree;
struct DSU{
    vector<int> pad;
    vector<set<pair<int,int>>> compo; 
    int find(int x){return x==pad[x]?x:pad[x]=find(pad[x]);}
    bool unite(int x,int y){
        if((x=find(x))==(y=find(y)))return false;
        if(compo[x].size()<compo[y].size())swap(x,y);
        pad[y]=x;
        for(auto u:compo[y])compo[x].insert(u);
        return true;
    }
    DSU(int x){
        pad.resize(x);
        compo.resize(x);
        for(int i=0;i<x;i++){
            pad[i]=i;
            compo[i].insert({0,i});
        }
    }
};
bool cmp(int a,int b){return degree[a]<degree[b];}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    graph.resize(n);
    posi.resize(n);
    degree.resize(n);
    set<pair<int,int>> ordennn; 
    while(m--){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        degree[i]=graph[i].size();
        ordennn.insert({degree[i],i});
    }
    vector<int> orden;
    while(!ordennn.empty()){
        int top=ordennn.begin()->second;
        orden.push_back(top);
        for(auto u:graph[top]){
            if(ordennn.find({degree[u],u})!=ordennn.end()){
                ordennn.erase({degree[u],u});
                degree[u]--;
                ordennn.insert({degree[u],u});
            }
        }
        ordennn.erase({degree[top],top});
    }
    reverse(ALL(orden));
    //for(auto u:orden)cout << u+1 << ' ';
    //14 9 1 5 8 3 12 15 13 4 11 6 2 16 10 7 
    // quitar los que tienen menor deg paso a paso
    pair<int,int> deg[n];
    for(int i=0;i<n;i++)deg[i]={graph[i].size(),i};
    sort(deg,deg+n);
    reverse(deg,deg+n);
    DSU clav(n);
    vector<int> degnow(n);
    for(int i=0;i<n;i++){
        int node=orden[i];
        posi[node]=true;
        for(auto u:graph[node]){
            if(!posi[u])continue;
            // añadir deg al deg[i].second y u
            int ances1=clav.find(node);
            int ances2=clav.find(u);
            clav.compo[ances1].erase({degnow[node],node});
            clav.compo[ances2].erase({degnow[u],u});
            degnow[node]++;
            degnow[u]++;
            clav.compo[ances1].insert({degnow[node],node});
            clav.compo[ances2].insert({degnow[u],u});
            clav.unite(u,node);
            int ances=clav.find(node);
            maxi=max(maxi,(ll)clav.compo[ances].size()*(clav.compo[ances].begin()->first));
        }
    }
    cout << maxi;
}