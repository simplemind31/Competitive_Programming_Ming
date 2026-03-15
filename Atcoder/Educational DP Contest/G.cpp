#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
int n,m,a,b,dp[100000],maxi;
vector<vector<int>> graph;
int solve(int node){
    if(dp[node])return dp[node];
    dp[node]=1;
    for(auto u:graph[node]){
        dp[node]=max(dp[node],solve(u)+1);
    }
    return dp[node];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    graph.resize(n);
    while(m--){
        cin >> a >> b;
        graph[--a].push_back(--b);
    }
    for(int i=0;i<n;i++){
        maxi=max(maxi,solve(i));
    }
    cout << maxi-1;
}