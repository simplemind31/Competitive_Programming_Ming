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
char c;
int n,m,tiempo,a,b,q;
vector<int> res;
map<pair<int,int>,int> hashv;
vector<int> queries;
vector<pair<pair<int,int>,pair<int,int>>> op;
PersistentDSU clav(0);
void solve(int l,int r,vector<pair<pair<int,int>,pair<int,int>>>& que){
    clav.persist();
    vector<pair<pair<int,int>,pair<int,int>>> nue;
    for(auto u:que){
        if(u.second==make_pair(-1,-1)){
            if(l<=u.first.first && u.first.first<=r)nue.push_back(u);
        }else{
            if(u.first.first<=l && r<=u.first.second)clav.unite(u.second.first,u.second.second);
            else if(u.first.second<l || r<u.first.first)continue;
            else nue.push_back(u);
        }
    }
    if(l==r){
        for(auto u:nue){
            if(u.second==make_pair(-1,-1))res[u.first.second]=clav.compo;
        }
        clav.rollback();
        return;
    }
    int mid=(l+r)>>1;
    solve(l,mid,nue);
    solve(mid+1,r,nue);
    clav.rollback();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    clav=PersistentDSU(n);
    while(m--){
        cin >> c;
        if(c=='?'){
            op.push_back({{++tiempo,q++},{-1,-1}});
        }else{
            cin >> a >> b;
            if(a-->b--)swap(a,b);
            if(c=='+'){
                hashv[{a,b}]=++tiempo;
            }else{
                op.push_back({{hashv[{a,b}],++tiempo},{a,b}});
                hashv.erase({a,b});
            }
        }
    }
    for(auto u:hashv)op.push_back({{u.second,++tiempo},{u.first.first,u.first.second}});
    res.resize(q);
    solve(0,tiempo,op);
    for(auto u:res)cout << u << '\n';
}