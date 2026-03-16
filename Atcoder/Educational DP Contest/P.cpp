#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,a,b,dp[100000][2];//0 blanco 1 negro
vector<int> graph[100000];
void solve(int node,int ante){
    dp[node][0]=dp[node][1]=1;
    for(auto u:graph[node]){
        if(u==ante)continue;
        solve(u,node);
        // si elijo negro, solo blanco
        dp[node][1]=1ll*dp[node][1]*dp[u][0]%MOD;
        // si elijo blanco, puedo elegir tanto blanco como negro
        dp[node][0]=1ll*dp[node][0]*(dp[u][0]+dp[u][1])%MOD;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    if(n==1){
        cout << 2;
        return 0;
    }
    while(--n){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    solve(0,-1);
    cout << (dp[0][0]+dp[0][1])%MOD;
}