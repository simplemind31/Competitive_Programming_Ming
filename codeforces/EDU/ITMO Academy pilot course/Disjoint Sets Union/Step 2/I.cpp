#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,t,a,b,shift,m;
struct DSU{
    vector<pair<int,int>> dsu;
    vector<int> tam;
    pair<int,int> find(int a){
        if(a==dsu[a].first)return {a,0};
        pair<int,int> tem=find(dsu[a].first);
        return dsu[a]={tem.first,(dsu[a].second+tem.second)%2};
    }
    bool unite(int a,int b){
        pair<int,int> ra=find(a),rb=find(b);
        if(tam[ra.first]<tam[ra.second])swap(ra,rb);
        tam[ra.first]+=tam[rb.first];
        dsu[rb.first]={ra.first,(ra.second+rb.second+1)%2};
        return true;
    }
    DSU(int n){
        tam.resize(n);
        dsu.resize(n);
        for(int i=0;i<n;i++){
            tam[i]=1;
            dsu[i]={i,0};
        }
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    DSU res(n);
    while(m--){
        cin >> t >> a >> b;
        a=(a+shift)%n;
        b=(b+shift)%n;
        if(t==0){
            res.unite(a,b);
        }else{
            shift+=(res.find(a).second==res.find(b).second);
            cout << ((res.find(a).second==res.find(b).second)?"YES":"NO") << '\n';
        }
    }
}