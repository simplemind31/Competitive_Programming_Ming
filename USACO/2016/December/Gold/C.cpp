#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,now;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("lasers.in","r",stdin);
    freopen("lasers.out","w",stdout);
    cin >> n;
    pair<int,int> pos[n+2];
    cin >> pos[0].first >> pos[0].second >> pos[n+1].first >> pos[n+1].second;
    for(int i=1;i<=n;i++)cin >> pos[i].first >> pos[i].second;
    map<int,int> ind;
    for(int i=0;i<=n+1;i++){
        if(ind[pos[i].first]==0)ind[pos[i].first]=++now;
        if(ind[pos[i].second]==0)ind[pos[i].second]=++now;
        pos[i].first=ind[pos[i].first]-1;
        pos[i].second=ind[pos[i].second]-1;
    }
    set<int> row[now],col[now];
    for(int i=0;i<=n+1;i++){
        row[pos[i].first].insert(i);
        col[pos[i].second].insert(i);
    }
    int dist[n+2];
    fill(dist,dist+(n+2),1e9);
    dist[0]=0;
    queue<int> bfs;
    row[pos[0].first].erase(0);
    col[pos[0].second].erase(0);
    bfs.push(0);
    while(!bfs.empty()){
        int top=bfs.front();
        bfs.pop();
        for(auto u:row[pos[top].first]){
            dist[u]=dist[top]+1;
            col[pos[u].second].erase(u);
            bfs.push(u);
        }
        row[pos[top].first].clear();
        for(auto u:col[pos[top].second]){
            dist[u]=dist[top]+1;
            row[pos[u].first].erase(u);
            bfs.push(u);
        }
        col[pos[top].second].clear();
    }
    cout << dist[n+1]-1;
}