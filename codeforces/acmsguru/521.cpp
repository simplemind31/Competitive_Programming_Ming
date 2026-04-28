#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n;
bool cmp(pair<pair<int,int>,int>& x,pair<pair<int,int>,int>& y){
    if(x.first.first==y.first.first)return x.first.second>y.first.second;
    return x.first.first<y.first.first;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    pair<pair<int,int>,int> cities[n+1];
    cities[0]={{-1e9,-1e9},0};
    for(int i=1;i<=n;i++){
        cin >> cities[i].first.first >> cities[i].first.second;
        cities[i].second=i;
    }
    sort(cities,cities+n+1,cmp);
    // lis
    int res[n+1];
    res[0]=0;
    set<pair<int,int>> lis;
    lis.insert({cities[0].first.second,0});
    for(int i=1;i<=n;i++){
        auto p=lis.lower_bound({cities[i].first.second,-1e9});
        auto ante=prev(p);
        if(p!=lis.end())lis.erase(p);
        res[i]=res[ante->second]+1;
        lis.insert({cities[i].first.second,i});
    }
    int tam=lis.size()-1;
    bool posi[n+1];
    memset(posi,0,sizeof(posi));
    set<int> posibles[tam+1];
    for(int i=n;i>=1;i--){
        if(res[i]==tam){
            posibles[res[i]].insert(cities[i].first.second);
            posi[i]=true;
            continue;
        }
        // buscar en posibles[res[i]+1] si alguno me puede necesitar
        if(posibles[res[i]+1].upper_bound(cities[i].first.second)!=posibles[res[i]+1].end()){
            posibles[res[i]].insert(cities[i].first.second);
            posi[i]=true;
        }
    }
    vector<int> contador(tam+1);
    vector<int> unico,superposi;
    for(int i=1;i<=n;i++){
        if(posi[i]){
            superposi.push_back(cities[i].second);
            contador[res[i]]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(posi[i]){
            if(contador[res[i]]==1)unico.push_back(cities[i].second);
        }
    }
    sort(ALL(unico));
    sort(ALL(superposi));
    cout << superposi.size() << ' ';
    for(auto u:superposi)cout << u <<  ' ';
    cout << '\n' << unico.size() << ' ';
    for(auto u:unico)cout << u << ' ';
}
/*
2 1 1 1
4 2 3 2
1 3 2 2
5 4 4 3
3 5 5 4

1 1 1 1
3 5 6 2
5 6 5 2
2 10 10 3
4 10 1 1
*/