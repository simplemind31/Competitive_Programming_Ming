#include <bits/stdc++.h>
#define imposi \
do{ \
    cout << "NO";\
    return 0; \
}while(0)
using namespace std;
typedef long long ll;
struct dsu{
    vector<int> pad,tam;
    int find(int x){return x==pad[x]?x:pad[x]=find(pad[x]);}
    bool unite(int x,int y){
        if((x=find(x))==(y=find(y)))return false;
        if(tam[x]<tam[y])swap(x,y);
        tam[pad[y]=x]+=tam[y];
        return true;
    }
    dsu(int x){
        pad.resize(x);
        tam.resize(x);
        for(int i=0;i<x;i++)tam[pad[i]=i]=1;
    }
};
int n;
vector<vector<ll>> dis;
vector<vector<pair<ll,ll>>> graph;
void dfs(int node,int ances,int pad){
    for(auto u:graph[node]){
        if(u.first==pad)continue;
        dis[ances][u.first]=dis[ances][node]+u.second;
        dfs(u.first,ances,node);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    dsu clav(n);
    graph.resize(n);
    vector mat(n,vector<ll>(n));
    dis=mat;
    vector<pair<int,pair<int,int>>> ed;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i][j];
            if(j<i){
                if(mat[i][j]!=mat[j][i] || !mat[i][j])imposi;
                ed.push_back({mat[i][j],{j,i}});
            }else if(j==i && mat[i][j])imposi;
        }
    }
    sort(ed.begin(),ed.end());
    for(auto u:ed){
        if(clav.unite(u.second.first,u.second.second)){
            graph[u.second.first].push_back({u.second.second,u.first});
            graph[u.second.second].push_back({u.second.first,u.first});
        }
    }
    for(int i=0;i<n;i++)dfs(i,i,-1);
    cout << (dis==mat?"YES":"NO");
}