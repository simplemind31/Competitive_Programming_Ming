#include <bits/stdc++.h>
using namespace std;
struct PersistentDSU{
    int compo;
    vector<int> dsu,tam;
    vector<pair<int,int>> ope;
    vector<int> checkpoint;
    int find(int a){return (a==dsu[a])?a:find(dsu[a]);}
    bool unite(int a,int b){
        if((a=find(a))==(b=find(b)))return false;
        if(tam[a]<tam[b])swap(a,b);
        tam[dsu[b]=a]+=tam[b];
        ope.push_back({b,a});
        compo--;
        return true;
    }
    void persist(){
        checkpoint.push_back(ope.size());
    }
    void rollback(){
        while(ope.size()>checkpoint.back()){
            dsu[ope.back().first]=ope.back().first;
            tam[ope.back().second]-=tam[ope.back().first];
            compo++;
            ope.pop_back();
        }
        checkpoint.pop_back();
    }
    PersistentDSU(int n){
        dsu.resize(n);
        tam.resize(n);
        for(int i=0;i<n;i++)tam[dsu[i]=i]=1;
        compo=n;
    }
};
struct DSU{
    int compo;
    vector<int> dsu,tam;
    int find(int a){return (a==dsu[a])?a:dsu[a]=find(dsu[a]);}
    bool unite(int a,int b){
        if((a=find(a))==(b=find(b)))return false;
        if(tam[a]<tam[b])swap(a,b);
        tam[dsu[b]=a]+=tam[b];
        compo--;
        return true;
    }
    DSU(int n){
        dsu.resize(n);
        tam.resize(n);
        for(int i=0;i<n;i++)tam[dsu[i]=i]=1;
        compo=n;
    }
};
int n,m,q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int raiz=sqrt(m);
    vector<pair<int,int>> edges(m);
    vector<pair<pair<int,int>,int>> blocks[(m-1)/raiz+1];
    for(int i=0;i<m;i++){
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }
    cin >> q;
    vector<pair<int,int>> queries(q);
    vector<int> res(q);
    for(int i=0;i<q;i++){
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--;
        queries[i].second--;
        blocks[queries[i].first/raiz].push_back({{queries[i].second,queries[i].first},i});
    }
    for(int i=0;i<(m-1)/raiz+1;i++){
        sort(blocks[i].begin(),blocks[i].end());
        // r, l ,ind
        PersistentDSU clav(n);
        int last=(i+1)*raiz-1;
        for(auto u:blocks[i]){
            if(u.first.first/raiz==i){
                clav.persist();
                for(int j=u.first.second;j<=u.first.first;j++){
                    clav.unite(edges[j].first,edges[j].second);
                }
                res[u.second]=clav.compo;
                clav.rollback();
                continue;
            }
            while(last<u.first.first){
                last++;
                clav.unite(edges[last].first,edges[last].second);
            }
            clav.persist();
            for(int j=(i+1)*raiz-1;j>=u.first.second;j--){
                clav.unite(edges[j].first,edges[j].second);
            }
            res[u.second]=clav.compo;
            clav.rollback();
        }
    }
    for(int i=0;i<q;i++){
        cout << res[i] << '\n';
    }
}