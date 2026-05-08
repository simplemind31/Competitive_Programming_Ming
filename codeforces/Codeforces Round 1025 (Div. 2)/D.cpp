#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,l;
ll a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m >> l;
        vector<int> graph[n];
        ll suma=0,miniimp=1e14;
        for(int i=0;i<l;i++){
            cin >> a;
            if(a&1)miniimp=min(miniimp,a);
            suma+=a;
        }
        while(m--){
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }
        int dist[n][2];
        fill(&dist[0][0],&dist[0][0]+2*n,2e9+1);
        dist[0][0]=0;
        queue<pair<int,bool>> bfs;
        bfs.push({0,0});
        while(!bfs.empty()){
            pair<int,bool> top=bfs.front();
            bfs.pop();
            for(auto u:graph[top.first]){
                if(dist[u][!top.second]==2e9+1){
                    dist[u][!top.second]=dist[top.first][top.second]+1;
                    bfs.push({u,!top.second});
                }
            }
        }
        ll par,impar;
        if(suma&1){
            impar=suma;
            par=suma-miniimp;
        }else{
            par=suma;
            impar=suma-miniimp;
        }
        for(int i=0;i<n;i++){
            if(dist[i][0]<=par || dist[i][1]<=impar)cout << 1;
            else cout << 0;
        }
        cout << '\n';
    }
}