#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,suma;
struct DSU{
    vector<int> dsu,tam;
    int find(int a){return (a==dsu[a])?a:dsu[a]=find(dsu[a]);}
    bool unite(int a,int b){
        if((a=find(a))==(b=find(b)))return false;
        if(tam[a]<tam[b])swap(a,b);
        tam[dsu[b]=a]+=tam[b];
        return true;
    }
    DSU(int n){
        dsu.resize(n+1);
        tam.resize(n+1);
        for(int i=0;i<=n;i++)tam[dsu[i]=i]=1;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    DSU res(n);
    pair<int,pair<int,int>> edges[m];
    for(int i=0;i<m;i++)cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    sort(edges,edges+m);
    for(int i=0;i<m;i++){
        if(res.unite(--edges[i].second.first,--edges[i].second.second))suma=edges[i].first;
    }
    cout << suma;
}