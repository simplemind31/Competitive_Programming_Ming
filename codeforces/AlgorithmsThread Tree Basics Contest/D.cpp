#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,c,q,m,len[300000],pad[300000][20],minlen[300000][20];
vector<pair<int,int>> graph[300000];
void dfs(int node,int ante){
    for(auto u:graph[node]){
        if(u.first==ante)continue;
        pad[u.first][0]=node;
        len[u.first]=len[node]+1;
        minlen[u.first][0]=u.second;
        dfs(u.first,node);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> c;
        graph[--a].push_back({--b,c});
        graph[b].push_back({a,c});
    }
    for(int i=0;i<n;i++)pad[i][0]=i;
    for(int i=0;i<n;i++){
        if(pad[i][0]==i){
            minlen[i][0]=1e9;
            dfs(i,-1);
        }
    }
    for(int j=1;j<20;j++){
        for(int i=0;i<n;i++){
            pad[i][j]=pad[pad[i][j-1]][j-1];
            minlen[i][j]=min(minlen[i][j-1],minlen[pad[i][j-1]][j-1]);
        }
    }
    cin >> q;
    while(q--){
        cin >> a >> b;
        if(len[--a]<len[--b])swap(a,b);
        int mini=1e9;
        for(int i=19;i>=0;i--){
            if((len[a]-len[b])&(1<<i)){
                mini=min(mini,minlen[a][i]);
                a=pad[a][i];
            }
        }
        if(a!=b){
            for(int i=19;i>=0;i--){
                if(pad[a][i]!=pad[b][i]){
                    mini=min({mini,minlen[a][i],minlen[b][i]});
                    a=pad[a][i];
                    b=pad[b][i];
                }
            }
            mini=min({mini,minlen[a][0],minlen[b][0]});
        }
        cout << mini << '\n';
    }
}