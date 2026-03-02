#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,m,suma,s;
struct DSU{
    vector<ll> dsu,tam;
    ll find(ll a){return (a==dsu[a])?a:dsu[a]=find(dsu[a]);}
    bool unite(ll a,ll b){
        if((a=find(a))==(b=find(b)))return false;
        if(tam[a]<tam[b])swap(a,b);
        tam[dsu[b]=a]+=tam[b];
        return true;
    }
    DSU(ll n){
        dsu.resize(n+1);
        tam.resize(n+1);
        for(ll i=0;i<=n;i++)tam[dsu[i]=i]=1;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> s;
    DSU res(n);
    pair<pair<ll,ll>,pair<ll,ll>> edges[m];
    ll tot=0;
    for(ll i=0;i<m;i++){
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first.first;
        tot+=edges[i].first.first;
        edges[i].first.second=i;
    }
    sort(edges,edges+m);
    reverse(edges,edges+m);
    vector<bool> used(m);
    vector<int> ind;
    for(ll i=0;i<m;i++){
        if(res.unite(--edges[i].second.first,--edges[i].second.second)){
            tot-=edges[i].first.first;
            used[edges[i].first.second]=true;
        }
    }
    for(int i=0;i<m && tot>s;i++){
        if(!used[edges[i].first.second]){
            tot-=edges[i].first.first;
            used[edges[i].first.second]=true;
        }
    }
    for(int i=0;i<m;i++)if(!used[i])ind.push_back(i);
    cout << ind.size() << '\n';
    for(auto u:ind)cout << u+1 << ' ';
}