#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,a,b;
ll val;
string st;
vector<vector<int>> graph;
struct DSU{
    vector<ll> tam,pad,res;
    int find(int x){return x==pad[x]?x:pad[x]=find(pad[x]);}
    bool unite(int x,int y){
        if((x=find(x))==(y=find(y)))return false;
        if(tam[x]<tam[y])swap(x,y);
        tam[pad[y]=x]+=tam[y];
        res[x]+=res[y];
        return true;
    }
    DSU(int x){
        tam.resize(x);
        res=pad=tam;
        for(int i=0;i<x;i++)tam[pad[i]=i]=1;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> st;
    vector<pair<int,int>> edges(m);
    vector<ll> res(n);
    graph.resize(n);
    DSU clav(n);
    for(int i=0;i<m;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
        if(st[a]+st[b]=='1'+'1')clav.unite(a,b);
    }
    for(int i=n-1;i>=0;i--){
        ll temp=clav.res[clav.find(i)];
        val-=temp*(temp-1)/2;
        clav.res[clav.find(i)]++;
        temp++;
        val+=temp*(temp-1)/2;
        for(auto u:graph[i]){
            if(clav.find(u)==clav.find(i))continue;
            if(st[u]=='1' || u>i){
                ll p1=clav.res[clav.find(u)];
                ll p2=clav.res[clav.find(i)];
                val-=p1*(p1-1)/2;
                val-=p2*(p2-1)/2;
                clav.unite(i,u);
                p1=clav.res[clav.find(i)];
                val+=p1*(p1-1)/2;
            }
        }
        res[i]=val;
    }
    for(int i=0;i<n;i++)cout << res[i] << '\n';
}