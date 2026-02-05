#include <bits/stdc++.h>
using namespace std;
int n,dsu[1001],tam[1001],x,y;
set<int> dif;
int find(int a){return (a==dsu[a])?a:dsu[a]=find(dsu[a]);}
bool unite(int a,int b){
    if((a=find(a))==(b=find(b)))return false;
    if(tam[b]>tam[a])swap(a,b);
    dif.erase(b);
    tam[a]+=tam[b];
    dsu[b]=a;
    return true;
}
template<typename A,typename B>ostream& operator<<(ostream& out,const pair<A, B>& p){
    out << p.first << ' ' << p.second;
    return out;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        tam[dsu[i]=i]=1;
        dif.insert(i);
    }
    vector<pair<int,int>> inutil;
    for(int i=1;i<n;i++){
        cin >> x >> y;
        if(!unite(x,y))inutil.push_back({x,y});
    }
    vector<pair<pair<int,int>,pair<int,int>>> res;
    while(dif.size()>1){
        x=*dif.begin();
        y=*next(dif.begin());
        res.push_back({inutil.back(),{x,y}});
        inutil.pop_back();
        unite(x,y);
    }
    cout << res.size() << '\n';
    for(auto u:res)cout << u << '\n';
}