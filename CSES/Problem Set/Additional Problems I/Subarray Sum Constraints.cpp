#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,l,r,s;
ll psum[5001];
bitset<5001> visited;
vector<pair<int,int>> graph[5001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> l >> r >> s;
        // psum[r]-psum[l-1]=s
        // psum[r]=psum[l-1]+s
        graph[l-1].push_back({r,s});
        graph[r].push_back({l-1,-s});
        // para que sea correcto el cada edge tiene que tener coherencia
    }
    bool xd=true;
    for(int i=0;i<=n;i++){
        if(visited[i])continue;
        visited[i]=true;
        psum[i]=0;
        queue<int> bfs;
        bfs.push(i);
        while(!bfs.empty() && xd){
            int top=bfs.front();
            bfs.pop();
            for(auto u:graph[top]){
                if(visited[u.first]){
                    if(psum[u.first]!=psum[top]+u.second){
                        xd=false;
                        break;
                    }
                    continue;
                }
                visited[u.first]=true;
                psum[u.first]=psum[top]+u.second;
                bfs.push(u.first);
            }
        }
        if(!xd){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for(int i=1;i<=n;i++){
        cout << psum[i]-psum[i-1] << ' ';
    }
}