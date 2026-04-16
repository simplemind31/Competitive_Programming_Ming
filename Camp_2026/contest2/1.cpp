#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
#define MOD 1000000007
int dp[1000001],n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6 && i-j>=0;j++){
            dp[i]=(dp[i]+dp[i-j])%MOD;
        }
    }
    cout << dp[n];
}