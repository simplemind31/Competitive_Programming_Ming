#include <bits/stdc++.h>
using namespace std;
int n,m,k,a,b;
vector<int> graph[200000];
int agri[200000],res[200000];
bitset<200000> visited;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> agri[i];
        agri[i]--;
    }
    while(m--){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    visited[0]=1;
    queue<pair<int,int>> bfs;
    bfs.push({0,0});
    while(!bfs.empty()){
        pair<int,int> top=bfs.front();
        bfs.pop();
        res[agri[top.first]]=top.second;
        for(auto u:graph[top.first]){
            if(visited[u])continue;
            visited[u]=1;
            bfs.push({u,top.second+1});
        }
    }
    for(int i=0;i<k;i++){
        cout << res[i] << ' ';
    }
}