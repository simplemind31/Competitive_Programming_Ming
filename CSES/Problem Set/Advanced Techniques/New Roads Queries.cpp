#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,q;
struct DSU{
    vector<ll> tam,pad;
    int find(int x){return x==pad[x]?x:pad[x]=find(pad[x]);}
    bool unite(int x,int y){
        if((x=find(x))==(y=find(y)))return false;
        if(tam[x]<tam[y])swap(x,y);
        tam[pad[y]=x]+=tam[y];
        return true;
    }
    DSU(int x){
        tam.resize(x);
        pad=tam;
        for(int i=0;i<x;i++)tam[pad[i]=i]=1;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    vector<int> lo(q,0),hi(q,m);
    vector<pair<int,int>> edges(m),queries(q);
    for(int i=0;i<m;i++){
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;edges[i].second--;
    }
    for(int i=0;i<q;i++){
        cin >> queries[i].first >> queries[i].second;
        if(queries[i].first==queries[i].second)lo[i]=hi[i]=-1;
        queries[i].first--;
        queries[i].second--;
    }
    while(true){
        bool changed=false;
        vector<int> bucket[m];
        for(int i=0;i<q;i++){
            if(lo[i]<hi[i]){
                changed=true;
                bucket[(lo[i]+hi[i])/2].push_back(i);
            }
        }
        if(!changed)break;
        DSU clav(n);
        for(int i=0;i<m;i++){
            clav.unite(edges[i].first,edges[i].second);
            for(auto u:bucket[i]){
                if(clav.find(queries[u].first)==clav.find(queries[u].second))hi[u]=i;
                else lo[u]=i+1;
            }
        }
    }
    for(int i=0;i<q;i++){
        if(lo[i]==m)cout << "-1\n";
        else cout << lo[i]+1 << '\n';
    }
}