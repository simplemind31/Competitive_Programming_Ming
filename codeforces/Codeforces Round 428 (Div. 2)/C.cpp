#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b;
double res;
vector<vector<int>> graph;
void solve(int node,int ante,int len,double prob){
    int con=0;
    if(graph[node].size()==1 && graph[node][0]==ante){
        res+=prob*len;
        return;
    }
    double nue;
    if(ante==-1)nue=prob/graph[node].size();
    else nue=prob/(graph[node].size()-1);
    for(auto u:graph[node]){
        if(u==ante)continue;
        solve(u,node,len+1,nue);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    graph.resize(n);
    while(--n){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    solve(0,-1,0,1);
    cout << fixed << setprecision(6) << res;
}