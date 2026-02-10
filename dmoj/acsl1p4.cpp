#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool retorno;
int n,m,a,b,x,y,visited,imposi,last,con;
vector<int> graph[20];
void dfs(int node){
    if(visited&(1<<node)){
        if(node==last)retorno=true;
        return;
    }
    visited+=(1<<node);
    for(auto u:graph[node]){
        dfs(u);
        if(retorno){
            imposi|=(1<<node);
            return;
        }
    }
    visited-=(1<<node);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> x >> y;
        if(x>y)graph[--a].push_back(--b);
        else graph[--b].push_back(--a);
    }
    for(int i=0;i<n;i++){
        if(imposi&(1<<i))continue;
        last=i;
        visited=0;
        retorno=false;
        dfs(i);
    }
    for(int i=0;i<n;i++)if(imposi&(1<<i))con++;
    cout << con;
}