#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
int t,n,S;
int bigmod(int b,int e){
    int p=1;
    for(;e;e>>=1,b=1ll*b*b%MOD)if(e&1)p=1ll*p*b%MOD;
    return p;
}
struct DSU{
    vector<int> pad,tam,res;
    int find(int x){return x==pad[x]?x:pad[x]=find(pad[x]);}
    int unite(int x,int y,int e){
        if((x=find(x))==(y=find(y)))return false;
        if(tam[x]<tam[y])swap(x,y);
        // todos X puede unir con todos de Y con un numero >e pero no unir x,y
        //tam[x]*tam[y]-1 posibles edges
        // cada edge puede ser de e+1 al S
        // habra S-(e+1)+1 posibilidades
        // habra S-e posibilidades por edge
        // si cuento el 0 entonces habra S-e+1 por edge
        // pow(S-e+1,tam[x]*tam[y]-1)
        res[x]=1ll*res[x]*res[y]%MOD*bigmod(S-e+1,tam[x]*tam[y]-1)%MOD;
        tam[pad[y]=x]+=tam[y];
        return true;
    }
    DSU(int x){
        tam.resize(x);
        pad.resize(x);
        for(int i=0;i<x;i++)tam[pad[i]=i]=1;
        res=tam;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> S;
        vector<pair<int,pair<int,int>>> edges(n-1);
        for(int i=0;i<n-1;i++)cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
        sort(edges.begin(),edges.end());
        DSU clav(n);
        for(int i=0;i<n-1;i++)clav.unite(--edges[i].second.first,--edges[i].second.second,edges[i].first);
        cout << clav.res[clav.find(0)] << '\n';
    }
}