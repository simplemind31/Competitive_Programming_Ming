#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
char c;
int q,k,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> q >> k;
    ll dp[k+1]={1};
    while(q--){
        cin >> c >> a;
        if(c=='+')for(int i=k;i>=a;i--)dp[i]=(dp[i]+dp[i-a])%MOD;
        else for(int i=a;i<=k;i++)dp[i]=(dp[i]-dp[i-a]+MOD)%MOD;
        cout << dp[k] << '\n';
    }
}