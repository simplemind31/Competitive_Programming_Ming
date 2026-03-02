#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,x,q,t,a,b;
struct DSU{
    vector<pair<int,int>> dsu;
    pair<int,int> find(int a){
        if(a==dsu[a].first)return {a,0};
        pair<int,int> tem=find(dsu[a].first);
        return dsu[a]={tem.first,dsu[a].second+tem.second};
    }
    void unite(int a,int b){dsu[a]={b,1};}
    DSU(int n){
        dsu.resize(n);
        for(int i=0;i<n;i++)dsu[i]={i,0};
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    DSU res(n);
    while(q--){
        cin >> t;
        if(t==1){
            cin >> a >> b;
            res.unite(--a,--b);
        }else{
            cin >> a;
            cout << res.find(--a).second << '\n';
        }
    }
}