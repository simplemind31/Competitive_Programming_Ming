#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
bitset<200000> visitededge,visitednode,existe;
vector<vector<pair<int,int>>> graph;
vector<tuple<int,int,int>> res;
// hijos primero luego padre
void dfs(int node,pair<int,int> pad){
    visitednode[node]=true;
    existe[node]=true;
    vector<pair<int,int>> temp;
    for(auto u:graph[node])if(!visitednode[u.first])dfs(u.first,{node,u.second});
    for(auto u:graph[node])if(!existe[u.first] && !visitededge[u.second])temp.push_back(u);
    if(pad!=make_pair(-1,-1) && (temp.size()&1))temp.push_back(pad);
    while(temp.size()>1){
        pair<int,int> prime=temp.back();
        temp.pop_back();
        pair<int,int> seg=temp.back();
        temp.pop_back();
        visitededge[prime.second]=visitededge[seg.second]=true;
        res.push_back({prime.first,node,seg.first});
    }
    existe[node]=false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    graph.resize(n);
    for(int i=0;i<m;i++){
        cin >> a >> b;
        graph[--a].push_back({--b,i});
        graph[b].push_back({a,i});
    }
    for(int i=0;i<n;i++)if(!visitednode[i])dfs(i,{-1,-1});
    cout << res.size() << '\n';
    for(auto u:res)cout << get<0>(u)+1 << ' ' << get<1>(u)+1 << ' ' << get<2>(u)+1 << '\n';
}