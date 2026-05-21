#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
vector<vector<int>> graph;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    graph.resize(n);
    while(m--){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
}