#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
string st;
int n,a;
struct cmp{
    bool operator()(const pair<int,int>& x,const pair<int,int>& y)const{
        if(x.second-x.first==y.second-y.first)return x.first<y.first;
        return x.second-x.first>y.second-y.first;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st >> n;
    vector<pair<int,int>> rang;
    set<pair<int,int>> normal;
    set<pair<int,int>,cmp> res;
    rang.push_back({0,0});
    for(int i=1;i<st.size();i++){
        if(st[i]==st[i-1])rang.back().second=i;
        else rang.push_back({i,i});
    }
    for(auto u:rang){
        res.insert(u);
        normal.insert(u);
    }
    while(n--){
        cin >> a;
        a--;
        // eliminar el rango que contiene a ese numero
        auto p=--normal.upper_bound({a+1,0});
        int l=p->first,r=p->second;
        if(l==a && r==a){
            // merge ambos lados
            if(a==0){
                auto ne=next(p);
                if(ne!=normal.end()){
                    int ner=ne->second;
                    int nel=ne->first;
                    normal.erase({nel,ner});
                    normal.insert({nel-1,ner});
                    res.erase({nel,ner});
                    res.insert({nel-1,ner});
                }else{
                    normal.insert({a,a});
                    res.insert({a,a});
                }
                normal.erase({l,r});
                res.erase({l,r});
            }else if(a==st.size()-1){
                if(p!=normal.begin()){
                    auto an=prev(p);
                    int anr=an->second;
                    int anl=an->first;
                    normal.erase({anl,anr});
                    normal.insert({anl,anr+1});
                    res.erase({anl,anr});
                    res.insert({anl,anr+1});
                }else{
                    normal.insert({a,a});
                    res.insert({a,a});
                }
                normal.erase({l,r});
                res.erase({l,r});
            }else{
                auto ne=next(p);
                int ner=ne->second;
                int nel=ne->first;
                auto an=prev(p);
                int anr=an->second;
                int anl=an->first;
                normal.erase({anl,anr});
                normal.erase({nel,ner});
                normal.erase({l,r});
                normal.insert({anl,ner});
                res.erase({anl,anr});
                res.erase({nel,ner});
                res.erase({l,r});
                res.insert({anl,ner});
            }
        }else if(l==a){
            // expandir iz 
            if(p!=normal.begin()){
                auto an=prev(p);
                int anr=an->second;
                int anl=an->first;
                normal.erase({anl,anr});
                normal.insert({anl,anr+1});
                res.erase({anl,anr});
                res.insert({anl,anr+1});
            }else{
                normal.insert({a,a});
                res.insert({a,a});
            }
            normal.erase({l,r});
            normal.insert({l+1,r});
            res.erase({l,r});
            res.insert({l+1,r});
        }else if(r==a){
            // expandir de
            auto ne=next(p);
            if(ne!=normal.end()){
                int ner=ne->second;
                int nel=ne->first;
                normal.erase({nel,ner});
                normal.insert({nel-1,ner});
                res.erase({nel,ner});
                res.insert({nel-1,ner});
            }else{
                normal.insert({a,a});
                res.insert({a,a});
            }
            normal.erase({l,r});
            normal.insert({l,r-1});
            res.erase({l,r});
            res.insert({l,r-1});
        }else{
            // reducir ambos lados
            normal.erase({l,r});
            normal.insert({l,a-1});
            normal.insert({a,a});
            normal.insert({a+1,r});
            res.erase({l,r});
            res.insert({l,a-1});
            res.insert({a,a});
            res.insert({a+1,r});
        }
        cout << res.begin()->second-res.begin()->first+1 << ' ';
    }
}