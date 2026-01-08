#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
int t,n,m,a,b;
vector<vector<int>> graph;
ll power2[300001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    power2[0]=1;
    for(int i=1;i<=300000;i++){
        power2[i]=2*power2[i-1];
        power2[i]%=MOD;
    }
    while(t--){
        cin >> n >> m;
        graph.clear();
        //graph.shrink_to_fit();
        graph.resize(n);
        vector<int> visited(n,2);
        while(m--){
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }
        ll res=1;
        for(int i=0;i<n && res;i++){
            if(visited[i]!=2)continue;
            int con[2];
            con[0]=con[1]=0;
            queue<int> bfs;
            bfs.push(i);
            visited[i]=0;
            while(!bfs.empty()){
                int top=bfs.front();
                bfs.pop();
                con[visited[top]]++;
                for(auto u:graph[top]){
                    if(visited[u]==2){
                        visited[u]=1-visited[top];
                        bfs.push(u);
                    }else if(visited[u]==visited[top]){
                        res=0;
                        break;
                    }
                }
            }
            //cout << con[0] << ' ' << con[1] << '\n';
            res*=(power2[con[0]]+power2[con[1]])%MOD;
            res%=MOD;
        }
        cout << res << '\n';
    }
}