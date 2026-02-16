#include <bits/stdc++.h>
using namespace std;
int n[2],m,a,b,pos[2],res;
vector<vector<int>> graph[2];
vector<int> alt[2];
void dfs(int node,int ante,int ind){
    if(alt[ind][node]>alt[ind][pos[ind]])pos[ind]=node;
    for(auto u:graph[ind][node]){
        if(u==ante)continue;
        alt[ind][u]=alt[ind][node]+1;
        dfs(u,node,ind);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<2;i++){
        cin >> n[i];
        graph[i].resize(n[i]);
        alt[i].resize(n[i]);
        for(int j=0;j<n[i]-1;j++){
            cin >> a >> b;
            graph[i][--a].push_back(--b);
            graph[i][b].push_back(a);
        }
        dfs(0,-1,i);
        alt[i][pos[i]]=0;
        dfs(pos[i],-1,i);
        res=max(res,alt[i][pos[i]]);
    }
    cout << max(res,(alt[0][pos[0]]+1)/2+(alt[1][pos[1]]+1)/2+1);
}