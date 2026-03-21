#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
int n,t,a,b;
vector<pair<int,int>> graph;
vector<int> dp,res;
int dfs(int node){
    if(graph[node]==make_pair(-1,-1))return 0;
    return dp[node]=(dfs(graph[node].first)+2+dfs(graph[node].second)+2)%MOD;
}
void dfs2(int node){
    if(graph[node]==make_pair(-1,-1))return;
    res[graph[node].first]=(dp[graph[node].first]+1+res[node])%MOD;
    res[graph[node].second]=(dp[graph[node].second]+1+res[node])%MOD;
    dfs2(graph[node].first);
    dfs2(graph[node].second);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        graph.clear();
        dp.clear();
        res.clear();
        res.resize(n);
        dp.resize(n);
        graph.resize(n);
        for(int i=0;i<n;i++){
            cin >> a >> b;
            graph[i]={--a,--b};
        }
        dfs(0);
        res[0]=dp[0];
        dfs2(0);
        for(int i=0;i<n;i++){
            cout << (res[i]+1)%MOD << ' ';
        }
        cout << '\n';
    }
}