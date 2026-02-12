#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
int n,a,b,par,imp;
vector<int> graph[100000];
void dfs(int node,int ante,int dep){
    if(dep&1)imp++;
    else par++;
    for(auto u:graph[node]){
        if(u!=ante)dfs(u,node,dep+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1,0);
    // cada par podria conectar a un impar, pero hay n-1 usaods
    cout << 1ll*par*imp-(n-1);
}