#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n,m,a,b,res[100000];
vector<int> graph[100000];
bitset<100000> visited;
int solve(int node){
    if(visited[node])return res[node];
    visited[node]=true;
    if(node==n-1)return res[node]=1;
    for(auto u:graph[node])res[node]=(res[node]+solve(u))%MOD;
    return res[node];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        graph[--a].push_back(--b);
    }
    cout << solve(0);
}
