#include <bits/stdc++.h>
using namespace std;
int n,m,res,ngo,s,v;
vector<pair<float,float>> gopher,hole;
vector<vector<int>> graph;
vector<int> mt;
vector<bool> used;
float sq(float a){return a*a;}
bool try_kuhn(int node){
    if(used[node])return false;
    used[node]=true;
    for(auto u:graph[node]){
        if(mt[u]==-1 || try_kuhn(mt[u])){
            mt[u]=node;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> n >> m >> s >> v){
        res=0;
        gopher.clear();
        hole.clear();
        graph.clear();
        s*=v;
        gopher.resize(n);
        ngo=n;
        hole.resize(m);
        for(int i=0;i<n;i++)cin >> gopher[i].first >> gopher[i].second;
        for(int j=0;j<m;j++)cin >> hole[j].first >> hole[j].second;
        if(n>m){
            swap(n,m);
            swap(gopher,hole);
        }
        graph.resize(n);
        mt.assign(m,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(sq(gopher[i].first-hole[j].first)+sq(gopher[i].second-hole[j].second)<=sq(s))graph[i].push_back(j);
            }
        }
        for(int i=0;i<n;i++){
            used.assign(n,false);
            if(try_kuhn(i))res++;
        }
        cout << ngo-res << '\n';
    }
}