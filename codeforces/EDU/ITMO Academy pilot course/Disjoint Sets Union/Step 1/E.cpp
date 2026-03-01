#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,a,b;
string st;
vector<int> dsu,tam,res;
int find(int a,bool unir){
    if(a==dsu[a]){
        if(unir)return res[a];
        return a;
    }
    if(unir && res[a]!=m)return res[a];
    if(res[a]==m)res[a]=find(dsu[a],true);
    return dsu[a]=find(dsu[a],false);
}
bool unite(int a,int b){
    if((a=find(a,false))==(b=find(b,false)))return false;
    if(tam[a]<tam[b])swap(a,b);
    if(b==find(0,false)){
        tam[dsu[a]=b]+=tam[a];
        return true;
    }
    tam[dsu[b]=a]+=tam[b];
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    dsu.resize(n);tam.resize(n);
    int hand[n][2];
    res.assign(n,m);
    pair<int,int> op[m];
    vector<pair<int,int>> edges;
    for(int i=0;i<n;i++){
        tam[dsu[i]=i]=1;
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
    for(int i=0;i<n;i++){
        if(find(0,false)==find(i,false))res[i]=-1;
    }
    for(int i=m-1;i>=0;i--){
        a=find(op[i].first,false);
        b=find(hand[op[i].first][op[i].second],false);
        if(a!=find(0,false) && b==find(0,false)){
            res[a]=i;
            unite(a,b);
        }else if(a==find(0,false) && b!=find(0,false)){
            res[b]=i;
            unite(a,b);
        }else{
            unite(a,b);
        }
    }
    for(int i=0;i<n;i++){
        find(i,false);
        cout << res[i] << '\n';
    }
}