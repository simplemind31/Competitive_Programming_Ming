#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b;
vector<int> hojas;
vector<vector<int>> graph;
void dfs(int node,int ante=-1){
    if(graph[node].size()==1)hojas.push_back(node);
    for(auto u:graph[node]){
        if(u==ante)continue;
        dfs(u,node);
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    graph.resize(n);
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0);
    cout << (hojas.size()+1)/2 << '\n';
    for(int i=1;i<hojas.size();i+=2){
        cout << hojas[i-1]+1 << ' ' << hojas[i]+1 << '\n';
    }
    if(hojas.size()&1)cout << hojas[0]+1 << ' ' << hojas.back()+1;
}
