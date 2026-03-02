#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,a,b;
string st;
vector<int> dsu,res;
vector<vector<int>> lis;
int find(int a){return (a==dsu[a])?a:dsu[a]=find(dsu[a]);}
bool unite(int a,int b){
    if((a=find(a))==(b=find(b)))return false;
    if(lis[a].size()<lis[b].size())swap(a,b);
    for(auto u:lis[b])lis[a].push_back(u);
    lis[b].clear();
    dsu[b]=a;
    return true;
}
void expand(int node){
    for(auto u:lis[node])res[u]=res[node];
    lis[node].clear();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    dsu.resize(n);
    int hand[n][2];
    res.assign(n,m);
    lis.resize(n);
    pair<int,int> op[m];
    vector<pair<int,int>> edges;
    for(int i=0;i<n;i++){
        dsu[i]=i;
        lis[i]={i};
        cin >> hand[i][0] >> hand[i][1];
        a=--hand[i][0];b=--hand[i][1];
        if(a<b)swap(a,b);
        if(b!=-2){
            edges.push_back({i,b});
            edges.push_back({i,a});
        }else if(a!=-2){
            edges.push_back({i,a});
        }
    }
    vector<bool> quitado(edges.size());
    for(int i=0;i<m;i++){
        cin >> op[i].first >> op[i].second;
        op[i].first--;op[i].second--;
        if(!quitado[lower_bound(ALL(edges),make_pair(op[i].first,hand[op[i].first][op[i].second]))-edges.begin()])quitado[lower_bound(ALL(edges),make_pair(op[i].first,hand[op[i].first][op[i].second]))-edges.begin()]=true;
        else quitado[lower_bound(ALL(edges),make_pair(op[i].first,hand[op[i].first][op[i].second]))-edges.begin()+1]=true;
    }
    for(int i=0;i<edges.size();i++){
        if(!quitado[i])unite(edges[i].first,edges[i].second);
    }
    res[find(0)]=-1;
    expand(find(0));
    for(int i=m-1;i>=0;i--){
        a=op[i].first;
        b=hand[op[i].first][op[i].second];
        if(find(a)!=find(0) && find(b)==find(0)){
            res[find(a)]=i;
            expand(find(a));
            unite(a,b);
        }else if(find(a)==find(0) && find(b)!=find(0)){
            res[find(b)]=i;
            expand(find(b));
            unite(a,b);
        }else{
            unite(a,b);
        }
    }
    for(int i=0;i<n;i++){
        cout << res[i] << '\n';
    }
}