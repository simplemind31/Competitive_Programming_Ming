#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,dsu[2001],c[2001],k[2001],tam[2001],usado[2001],sum;
pair<ll,ll> city[2001];
vector<pair<ll,pair<ll,ll>>> orden;
vector<pair<ll,ll>> res;
vector<ll> resusado;
int find(int a){return (a==dsu[a])?a:dsu[a]=find(dsu[a]);}
bool unite(int a,int b){
    if((a=find(a))==(b=find(b)))return false;
    if(tam[a]<tam[b])swap(a,b);
    tam[dsu[b]=a]+=tam[b];
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i=0;i<=n;i++)tam[dsu[i]=i]=1;
    for(int i=1;i<=n;i++)cin >> city[i].first >> city[i].second;
    for(ll i=1;i<=n;i++)cin >> c[i];
    for(ll i=1;i<=n;i++)cin >> k[i];
    for(ll i=1;i<=n;i++){
        orden.push_back({c[i],{i,0}});
        for(ll j=i+1;j<=n;j++){
            orden.push_back({(k[i]+k[j])*(abs(city[i].first-city[j].first)+abs(city[i].second-city[j].second)),{i,j}});
        }
    }
    sort(ALL(orden));
    for(auto top:orden){
        if(!unite(top.second.first,top.second.second))continue;
        if(top.second.second==0)resusado.push_back(top.second.first);
        else res.push_back(top.second);
        sum+=top.first;
    }
    cout << sum << '\n' << resusado.size() << '\n';
    for(auto u:resusado)cout << u << ' ';
    cout << '\n' << res.size() << '\n';
    for(auto u:res)cout << u.first << ' ' << u.second << '\n';
}