#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,t,a,b,shift,m;
string st;
struct PersistentDSU{
    int compo;
    vector<int> dsu,tam;
    vector<pair<int,int>> ope;
    vector<int> checkpoint;
    int find(int a){return (a==dsu[a])?a:find(dsu[a]);}
    bool unite(int a,int b){
        if((a=find(a))==(b=find(b)))return false;
        if(tam[a]<tam[b]);
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
        tam.resize(n);
        dsu.resize(n);
        for(int i=0;i<n;i++)tam[dsu[i]=i]=1;
        compo=n;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    PersistentDSU res(n);
    while(m--){
        cin >> st;
        if(st=="persist")res.persist();
        else{
            if(st=="union"){
                cin >> a >> b;
                a--;b--;
                res.unite(a,b);
            }else res.rollback();
            cout << res.compo << '\n';
        }
    }
}