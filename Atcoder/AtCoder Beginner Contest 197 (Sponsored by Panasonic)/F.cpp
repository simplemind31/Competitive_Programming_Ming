#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char c;
int n,m,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int dist[n][n];
    fill(&dist[0][0],&dist[0][0]+n*n,1e9);
    queue<pair<int,int>> bfs;
    bool edge[n][n][26];
    memset(edge,0,sizeof(edge));
    vector<int> va[n][26];
    for(int i=0;i<n;i++){
        dist[i][i]=0;
        bfs.push({i,i});
    }
    while(m--){
        cin >> a >> b >> c;
        va[--a][c-'a'].push_back(--b);
        va[b][c-'a'].push_back(a);
        if(dist[a][b]==1e9){
            dist[a][b]=dist[b][a]=1;
            bfs.push({a,b});
            bfs.push({b,a});
        }
        edge[a][b][c-'a']=edge[b][a][c-'a']=1;
    }
    while(!bfs.empty()){
        pair<int,int> top=bfs.front();
        bfs.pop();
        for(int i=0;i<26;i++){
            for(auto u:va[top.first][i]){
                for(auto v:va[top.second][i]){
                    if(dist[u][v]==1e9){
                        dist[u][v]=dist[top.first][top.second]+2;
                        bfs.push({u,v});
                    }
                }
            }
        }
    }
    if(dist[0][n-1]==1e9)dist[0][n-1]=-1;
    cout << dist[0][n-1];
}