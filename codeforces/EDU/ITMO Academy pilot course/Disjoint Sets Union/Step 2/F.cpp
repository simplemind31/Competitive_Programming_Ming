#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,m;
ll mini=1e18;
struct DSU{
    ll compo;
    vector<ll> dsu,tam;
    ll find(ll a){return (a==dsu[a])?a:dsu[a]=find(dsu[a]);}
    bool unite(ll a,ll b){
        if((a=find(a))==(b=find(b)))return false;
        if(tam[a]<tam[b])swap(a,b);
        tam[dsu[b]=a]+=tam[b];
        compo--;
        return true;
    }
    DSU(ll n){
        dsu.resize(n);
        tam.resize(n);
        compo=n;
        for(ll i=0;i<n;i++)tam[dsu[i]=i]=1;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    pair<ll,pair<ll,ll>> edges[m];
    for(ll i=0;i<m;i++)cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    sort(edges,edges+m);
    for(ll i=0;i<m;i++){
        DSU res(n);
        ll tem=edges[i].first;
        for(ll j=i;j<m && res.compo>1;j++){
            if(res.unite(edges[j].second.first-1,edges[j].second.second-1))tem=edges[j].first;
        }
        if(res.compo>1)break;
        mini=min(mini,tem-edges[i].first);
    }
    if(mini==1e18)cout << "NO";
    else cout << "YES\n" << mini;
}