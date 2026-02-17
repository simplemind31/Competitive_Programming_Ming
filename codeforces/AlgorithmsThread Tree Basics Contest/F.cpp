#include <bits/stdc++.h>
#define LsOne(x) x&(-x)
using namespace std;
typedef long long ll;
ll n,a,b,q,tiempo,t,x,y,p;
vector<ll> len;
vector<pair<ll,ll>> entrasal;
vector<vector<ll>> graph;
struct BIT{
    vector<ll> fenwick;
    void update(ll pos,ll val){
        while(pos<=tiempo){
            fenwick[pos]+=val;
            pos+=LsOne(pos);
        }
    }
    ll sum(ll pos){
        ll suma=0;
        while(pos>0){
            suma+=fenwick[pos];
            pos-=LsOne(pos);
        }
        return suma;
    }
    ll rango(pair<ll,ll> par){
        return sum(par.second)-sum(par.first-1);
    }
    BIT(ll a){
        fenwick.resize(tiempo+2);
    }
};
void dfs(ll node,ll ante){
    entrasal[node].first=++tiempo;
    for(auto u:graph[node]){
        if(u==ante)continue;
        len[u]=len[node]+1;
        dfs(u,node);
    }
    entrasal[node].second=tiempo;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        tiempo=0;
        cin >> n >> q;
        graph.clear();
        entrasal.clear();
        len.clear();
        graph.resize(n+1);
        entrasal.resize(n+1);
        len.resize(n+1);
        for(ll i=1;i<n;i++){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(1,-1);
        BIT sol(0);
        while(q--){
            cin >> x >> y >> p;
            if(p>0){
                sol.update(entrasal[x].first,p);
                sol.update(entrasal[y].first,-p);
            }else{
                if(len[x]>len[y])swap(x,y);
                cout << abs(sol.rango(entrasal[y])) << '\n';//-sol.sum(entrasal[x].first)) << '\n';
            }
        }
    }
}