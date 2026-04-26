#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
int t,n;
string x,y;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> x >> y;
        int dp[n+1]={0};
        dp[1]=x[0]!=y[0];
        for(int i=2;i<=n;i++)dp[i]=min(dp[i-2]+(x[i-1]!=x[i-2])+(y[i-1]!=y[i-2]),dp[i-1]+(x[i-1]!=y[i-1]));
        cout << dp[n] << '\n';
    }
}