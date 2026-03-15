#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
int n;
double dp[3000],p;
vector<vector<int>> graph;
int solve(int node){
    if(dp[node])return dp[node];
    dp[node]=1;
    for(auto u:graph[node]){
        dp[node]=max(dp[node],(double)solve(u)+1);
    }
    return dp[node];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    dp[0]=1;
    for(int i=0;i<n;i++){
        cin >> p;
        for(int j=3000;j>=1;j--){
            dp[j]=dp[j]*(1-p)+dp[j-1]*p;
        }
        dp[0]=dp[0]*(1-p);
    }
    p=0;
    for(int i=0;i<=n;i++){
       cout << dp[i] << '\n';
    }
    cout << fixed << setprecision(12) << p;
}