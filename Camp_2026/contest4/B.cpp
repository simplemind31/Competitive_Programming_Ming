#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,k,m;
vector<ll> importantes;
vector<vector<ll>> dist;
vector<vector<pair<ll,ll>>> graph;
struct DSU{
    ll compo;
    vector<ll> tam,pad;
    ll find(ll a){return (a==pad[a])?a:pad[a]=find(pad[a]);}
    bool unite(ll a,ll b){
        if((a=find(a))==(b=find(b)))return false;
        if(tam[a]<tam[b])swap(a,b);
        tam[pad[b]=a]+=tam[b];
        return true;
    }
    DSU(ll x){
        compo=x;
        tam.resize(x);
        pad.resize(x);
        for(ll i=0;i<x;i++)tam[pad[i]=i]=1;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k >> m;
    graph.resize(n);
    vector<pair<ll,pair<ll,ll>>> edges(m);
    importantes.resize(k);
    for(ll i=0;i<k;i++){
        cin >> importantes[i];
        importantes[i]--;
    }
    for(ll i=0;i<m;i++){
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
        graph[--edges[i].second.first].push_back({--edges[i].second.second,edges[i].first});
        graph[edges[i].second.second].push_back({edges[i].second.first,edges[i].first});
    }
    sort(ALL(edges));
    ll mini=1e18;
    if(n<=20){
        for(ll i=0;i<(1<<n);i++){
            bool xd=true;
            for(auto u:importantes)if(!(i&(1<<u)))xd=false;
            if(!xd)continue;
            ll res=0;
            DSU clav(n);
            // solo unir estos
            ll contaaa=0;
            //if(i==(1<<n)-1)cout << "a";
            for(ll j=0;j<m;j++){
                if((i&(1<<edges[j].second.first))&&(i&(1<<edges[j].second.second))){
                    if(clav.unite(edges[j].second.first,edges[j].second.second)){
                        res+=edges[j].first;
                        contaaa++;
                    }
                }
            }
            if(contaaa==__builtin_popcount(i)-1)mini=min(mini,res);
        }
        cout << mini;
    }else if(k<=3){
        dist.resize(k);
        for(ll i=0;i<k;i++)dist[i].assign(n,1e18);
        for(int i=0;i<k;i++){
            dist[i][importantes[i]]=0;
            priority_queue<pair<ll,ll>> dij;
            dij.push({0,importantes[i]});
            while(!dij.empty()){
                pair<ll,ll> top=dij.top();
                dij.pop();
                if(-top.first>dist[i][top.second])continue;
                for(auto u:graph[top.second]){
                    if(dist[i][u.first]>dist[i][top.second]+u.second){
                        dist[i][u.first]=dist[i][top.second]+u.second;
                        dij.push({-dist[i][u.first],u.first});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            ll now=0;
            for(int j=0;j<k;j++){
                now+=dist[j][i];
            }
            mini=min(mini,now);
        }
        cout << mini;
    }else if(k==4){
        dist.resize(n);
        for(ll i=0;i<n;i++)dist[i].assign(n,1e18);
        for(int i=0;i<n;i++){
            dist[i][i]=0;
            priority_queue<pair<ll,ll>> dij;
            dij.push({0,i});
            while(!dij.empty()){
                pair<ll,ll> top=dij.top();
                dij.pop();
                if(-top.first>dist[i][top.second])continue;
                for(auto u:graph[top.second]){
                    if(dist[i][u.first]>dist[i][top.second]+u.second){
                        dist[i][u.first]=dist[i][top.second]+u.second;
                        dij.push({-dist[i][u.first],u.first});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //0,1 al i, 2,3 al j i al j
                ll now=dist[importantes[0]][i]+dist[importantes[1]][i]+dist[importantes[2]][j]+dist[importantes[3]][j]+dist[i][j];
                mini=min(mini,now);
                now=dist[importantes[0]][i]+dist[importantes[2]][i]+dist[importantes[1]][j]+dist[importantes[3]][j]+dist[i][j];
                mini=min(mini,now);
                now=dist[importantes[0]][i]+dist[importantes[3]][i]+dist[importantes[1]][j]+dist[importantes[2]][j]+dist[i][j];
                mini=min(mini,now);
            }
        }
        cout << mini;
    }
}