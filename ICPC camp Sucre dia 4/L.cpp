#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,m,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<int> graph[n];
    while(m--){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    int pad[n],dist[n];
    memset(dist,0,sizeof(dist));
    queue<int> cola;
    cola.push(n-1);
    while(!cola.empty()){
        int top=cola.front();
        cola.pop();
        for(auto u:graph[top]){
            if(dist[u]==0){
                dist[u]=dist[top]+1;
                pad[u]=top;
                cola.push(u);
            }
        }
    }
    if(dist[0]==0){
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << dist[0]+1 << '\n';
    int now=0;
    cout << now+1 << ' ';
    while(now!=n-1){
        now=pad[now];
        cout << now+1 << ' ';
    }
}
