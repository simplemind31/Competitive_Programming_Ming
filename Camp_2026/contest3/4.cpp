#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
struct dsu{
    vector<int> pad,tam;
    int compo;
    int find(int x){return (pad[x]==x)?x:pad[x]=find(pad[x]);}
    bool unite(int x,int y){
        if((x=find(x))==(y=find(y)))return false;
        if(tam[x]<tam[y])swap(x,y);
        tam[pad[y]=x]+=tam[y];
        compo--;
        return true;
    }
    dsu(int x){
        compo=x;
        pad.resize(x);
        tam.resize(x);
        for(int i=0;i<x;i++)tam[pad[i]=i]=1;
    }
};
int m,n;
ll res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<pair<int,pair<int,int>>> edges(m);
    dsu clav(n);
    for(int i=0;i<m;i++)cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    sort(ALL(edges));
    for(int i=0;i<m;i++)if(clav.unite(--edges[i].second.first,--edges[i].second.second))res+=edges[i].first;
    if(clav.compo==1)cout << res;
    else cout << "IMPOSSIBLE";
}