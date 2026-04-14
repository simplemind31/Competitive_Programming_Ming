#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
#define MOD 1000000007
int dp[1000001],n;
int solve(int x){
    if(x==0)return 0;
    if(dp[x])return dp[x];
    dp[x]=1e9;
    int a=x;
    while(a){
        if(a%10)dp[x]=min(dp[x],solve(x-a%10));
        a/=10;
    }
    dp[x]++;
    return dp[x];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    cout << solve(n);
}