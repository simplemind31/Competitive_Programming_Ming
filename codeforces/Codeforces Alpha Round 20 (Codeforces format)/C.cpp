#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
bitset<100000> visited;
int t,n,m,a,b,c,pad[100000];
ll dist[100000];
vector<pair<int,ll>> graph[100000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        pad[i]=-1;
        dist[i]=1e18;
    }
    while(m--){
        cin >> a >> b >> c;
        if(a==b)continue;
        graph[--a].push_back({--b,c});
        graph[b].push_back({a,c});
    }
    dist[0]=0;
    priority_queue<pair<ll,int>> dij;
    dij.push({0,0});
    while(!dij.empty()){
        int top=dij.top().second;
        dij.pop();
        if(visited[top])continue;
        visited[top]=true;
        for(auto u:graph[top]){
            if(dist[u.first]>dist[top]+u.second){
                dist[u.first]=dist[top]+u.second;
                pad[u.first]=top;
                dij.push({-dist[u.first],u.first});
            }
        }
    }
    if(!visited[n-1]){
        cout << -1;
        return 0;
    }
    vector<int> res;
    int now=n-1;
    res.push_back(now);
    while(now!=0)res.push_back(now=pad[now]);
    reverse(ALL(res));
    for(auto u:res)cout << u+1 << ' ';
}