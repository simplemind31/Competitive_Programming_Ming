#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,con;
vector<int> graph[100000];
void dfs(int node,int ante){
    con=max(con,(int)graph[node].size()+1);
    for(auto u:graph[node])if(u!=ante)dfs(u,node);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("planting.in","r",stdin);
    freopen("planting.out","w",stdout);
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    cout << con;
}