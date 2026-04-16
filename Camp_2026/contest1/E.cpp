#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b,m,c;
vector<vector<pair<ll,ll>>> g,graph;
vector<ll> tam,volver,supermegares;
vector<pair<ll,ll>> res[2];
vector<bool> necesa;
void quitarpadre(int node,int ante=-1){
    for(auto u:g[node]){
        if(u.first==ante)continue;
        graph[node].push_back(u);
        quitarpadre(u.first,node);
    }
}
void dfs(ll node){
    tam[node]=res[0][node].first=res[0][node].second=volver[node]=0;
    if(necesa[node])tam[node]++;
    if(graph[node].size()==0)return;
    ll mini1=0,mini2=0,ind1=-1,ind2=-1;
    for(auto u:graph[node]){
        dfs(u.first);
        tam[node]+=tam[u.first];
        // res0 < res1
        if(tam[u.first]){
            volver[node]+=volver[u.first]+2*u.second;
            if(-(volver[u.first]+2*u.second)+(res[0][u.first].first+u.second)<mini1){
                mini2=mini1;
                ind2=ind1;
                mini1=-(volver[u.first]+2*u.second)+(res[0][u.first].first+u.second);
                ind1=u.first;
            }else if(-(volver[u.first]+2*u.second)+(res[0][u.first].first+u.second)<mini2){
                mini2=-(volver[u.first]+2*u.second)+(res[0][u.first].first+u.second);
                ind2=u.first;
            }
        }
    }
    //cout << node << ' ' << tamsub << '\n';
    // no vuelvo? en cual me quedo?-> min(volver de todos menos uno)
    res[0][node]={volver[node]+mini1,ind1};
    res[1][node]={volver[node]+mini2,ind2};
}
void reroot(int node){
    supermegares[node]=res[0][node].first;
    for(auto u:graph[node]){
        // quitar informacion del hijo
        ll tempvol=volver[node],temptam=tam[node];
        pair<ll,ll> tempres0=res[0][node],tempres1=res[1][node];
        if(tam[u.first]){
            tam[node]-=tam[u.first];
            volver[node]-=volver[u.first]+2*u.second;
            if(res[0][node].second==u.first)res[0][node]=res[1][node];
            res[0][node].first-=volver[u.first]+2*u.second;
        }
        // añadir informacion del padre al hijo
        ll tempvolhi=volver[u.first],temptamhi=tam[u.first];
        pair<ll,ll> tempres0hi=res[0][u.first],tempres1hi=res[1][u.first];
        if(tam[node]){
            tam[u.first]+=tam[node];
            volver[u.first]+=volver[node]+2*u.second;
            res[0][u.first].first+=volver[node]+2*u.second;
            res[1][u.first].first+=volver[node]+2*u.second;
            // elegir node tal vez para entrar;
            if(volver[u.first]-(volver[node]+2*u.second)+res[0][node].first+u.second<res[0][u.first].first){
                res[1][u.first]=res[0][u.first];
                res[0][u.first]={volver[u.first]-(volver[node]+2*u.second)+res[0][node].first+u.second,node};
            }else if(volver[u.first]-(volver[node]+2*u.second)+res[0][node].first+u.second<res[1][u.first].first){
                res[1][u.first]={volver[u.first]-(volver[node]+2*u.second)+res[0][node].first+u.second,node};
            }
        }
        reroot(u.first);
        volver[node]=tempvol;
        tam[node]=temptam;
        res[0][node]=tempres0;
        res[1][node]=tempres1;
        volver[u.first]=tempvolhi;
        tam[u.first]=temptamhi;
        res[0][u.first]=tempres0hi;
        res[1][u.first]=tempres1hi;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    supermegares.resize(n);
    volver.resize(n);
    g.resize(n);
    graph.resize(n);
    tam.resize(n);
    res[0].resize(n);
    res[1].resize(n);
    volver.resize(n);
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
    reroot(0);
    for(int i=0;i<n;i++)cout << supermegares[i] << '\n';
    /*for(int i=0;i<n;i++){
        graph.clear();
        graph.resize(n);
        quitarpadre(i);
        dfs(i);
        cout << min(res[0][i].first,volver[i]) << '\n';
    }*/
    //for(int i=0;i<n;i++)cout << supermegares[i] << '\n';
}
