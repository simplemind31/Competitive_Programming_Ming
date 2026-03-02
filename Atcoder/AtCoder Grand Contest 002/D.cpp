#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,q;
struct DSU{
    vector<int> dsu,tam;
    int find(int a){return (a==dsu[a])?a:dsu[a]=find(dsu[a]);}
    bool unite(int a,int b){
        if((a=find(a))==(b=find(b)))return false;
        if(tam[a]<tam[b])swap(a,b);
        tam[dsu[b]=a]+=tam[b];
        return true;
    }
    DSU(int n){
        dsu.resize(n);
        tam.resize(n);
        for(int i=0;i<n;i++)tam[dsu[i]=i]=1;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    pair<int,int> edges[m];
    for(int i=0;i<m;i++){
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }
    cin >> q;
    pair<pair<int,int>,int> query[q];
    int lo[q],hi[q];
    for(int i=0;i<q;i++){
        lo[i]=0;
        hi[i]=m-1;
        cin >> query[i].first.first >> query[i].first.second >> query[i].second;
        query[i].first.first--;
        query[i].first.second--;
    }
    int con=0;
    while(true){
        bool changed=false;
        vector<vector<int>> bucket(m);
        for(int i=0;i<q;i++){
            if(lo[i]<hi[i]){
                changed=true;
                bucket[(lo[i]+hi[i])>>1].push_back(i);
            }
        }
        if(!changed)break;
        DSU clave(n);
        for(int i=0;i<m;i++){
            clave.unite(edges[i].first,edges[i].second);
            for(auto u:bucket[i]){
                int val=0;
                if(clave.find(query[u].first.first)==clave.find(query[u].first.second))val=clave.tam[clave.find(query[u].first.first)];
                else val=clave.tam[clave.find(query[u].first.first)]+clave.tam[clave.find(query[u].first.second)];
                if(val>=query[u].second)hi[u]=i;
                else lo[u]=i+1;
            }
        }
        /*for(int i=0;i<q;i++)cout << lo[i] << ' ';
        cout << '\n';
        for(int i=0;i<q;i++)cout << hi[i] << ' ';
        cout << '\n';
        if(con++==1)break;*/
    }
    for(int i=0;i<q;i++){
        cout << lo[i]+1 << '\n';
    }
}