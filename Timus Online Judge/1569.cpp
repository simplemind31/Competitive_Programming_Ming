#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,mini=1e9,pos;
bool existe[100][100];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<int> graph[n];
    vector<pair<int,int>> edge;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        edge.push_back({--a,--b});
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int j=0;j<m;j++){
        vector<int> dist(n,1e9);
        queue<int> bfs;
        bfs.push(edge[j].first);
        bfs.push(edge[j].second);
        dist[edge[j].first]=0;
        dist[edge[j].second]=0;
        int maxi=0;
        while(!bfs.empty()){
            int top=bfs.front();
            bfs.pop();
            for(auto u:graph[top]){
                if(dist[u]==1e9){
                    dist[u]=dist[top]+1;
                    bfs.push(u);
                    maxi=dist[u];
                }
            }
        }
        if(maxi<mini){
            mini=maxi;
            pos=j;
        }
    }
    vector<int> dist(n,1e9);
    cout << edge[pos].first+1 << ' ' << edge[pos].second+1 << '\n';
    dist[edge[pos].first]=dist[edge[pos].second]=0;
    queue<int> bfs;
    bfs.push(edge[pos].first);
    bfs.push(edge[pos].second);
    while(!bfs.empty()){
        int top=bfs.front();
        bfs.pop();
        for(auto u:graph[top]){
            if(dist[u]==1e9){
                cout << top+1 << ' ' << u+1 << '\n';
                dist[u]=dist[top]+1;
                bfs.push(u);
            }
        }
    }
}