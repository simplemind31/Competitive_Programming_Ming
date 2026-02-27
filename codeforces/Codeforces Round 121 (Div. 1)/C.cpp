#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
const int MAXN=100000;
int n,q,a,b,alt[MAXN],pad[MAXN][20],res[MAXN];
vector<int> graph[MAXN];
void dfs(int node,int ante){
    for(auto u:graph[node]){
        if(u==ante)continue;
        alt[u]=alt[node]+1;
        pad[u][0]=node;
        dfs(u,node);
        res[node]+=res[u];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<pair<int,int>> edges;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
        edges.push_back({a,b});
    }
    dfs(0,-1);
    for(int i=1;i<20;i++){
        for(int j=0;j<n;j++){
            pad[j][i]=pad[pad[j][i-1]][i-1];
        }
    }
    cin >> q;
    while(q--){
        cin >> a >> b;
        a--;b--;
        if(alt[a]<alt[b])swap(a,b);
        res[a]++;
        res[b]++;
        for(int i=19;i>=0;i--){
            if(alt[pad[a][i]]>=alt[b])a=pad[a][i];
        }
        if(a!=b){
            for(int i=19;i>=0;i--){
                if(pad[a][i]!=pad[b][i]){
                    a=pad[a][i];
                    b=pad[b][i];
                }
            }
            a=pad[a][0];
        }
        res[a]-=2;
    }
    dfs(0,-1);
    for(auto u:edges){
        if(alt[u.first]<alt[u.second])swap(u.first,u.second);
        cout << res[u.first] << ' ';
    }
}