#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll B,E,P,N,M,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("piggyback.in","r",stdin);
    freopen("piggyback.out","w",stdout);
    cin >> B >> E >> P >> N >> M;
    vector<ll> graph[N];
    while(M--){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    ll dist[3][N];
    fill(&dist[0][0],&dist[0][0]+3*N,1e10);
    // empezar en 0
    queue<ll> bfs;
    bfs.push(0);
    dist[0][0]=0;
    while(!bfs.empty()){
        ll top=bfs.front();
        bfs.pop();
        for(auto u:graph[top]){
            if(dist[0][u]==1e10){
                dist[0][u]=dist[0][top]+1;
                bfs.push(u);
            }
        }
    }
    bfs.push(1);
    dist[1][1]=0;
    while(!bfs.empty()){
        ll top=bfs.front();
        bfs.pop();
        for(auto u:graph[top]){
            if(dist[1][u]==1e10){
                dist[1][u]=dist[1][top]+1;
                bfs.push(u);
            }
        }
    }
    bfs.push(N-1);
    dist[2][N-1]=0;
    while(!bfs.empty()){
        ll top=bfs.front();
        bfs.pop();
        for(auto u:graph[top]){
            if(dist[2][u]==1e10){
                dist[2][u]=dist[2][top]+1;
                bfs.push(u);
            }
        }
    }
    ll mini=1e10;
    for(ll i=0;i<N;i++){
        mini=min(mini,dist[0][i]*B+dist[1][i]*E+dist[2][i]*P);
    }
    cout << mini;
}