#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,m,o,res;
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    if(a.second==b.second)return a.first<b.first;
    return a.second>b.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> o;
    vector<pair<ll,ll>> cuartos(n);
    vector<pair<ll,ll>> ofertas(m);
    for(ll i=0;i<n;i++)cin >> cuartos[i].second >> cuartos[i].first;
    for(ll i=0;i<m;i++)cin >> ofertas[i].second >> ofertas[i].first;
    multiset<pair<ll,ll>> option(ALL(cuartos));
    //capacidad,costo
    sort(ALL(ofertas),cmp);
    vector<ll> posibles;
    for(int i=0;i<m;i++){
        auto p=option.lower_bound({ofertas[i].first,0});
        if(p==option.end())continue;
        posibles.push_back({ofertas[i].second-p->second});
        option.erase(p);
    }
    sort(ALL(posibles));
    reverse(ALL(posibles));
    for(int i=0;i<min((ll)posibles.size(),o) && posibles[i]>0;i++){
        res+=posibles[i];
    }
    cout << res;
}