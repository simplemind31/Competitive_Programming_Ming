#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int t=1,n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<ll> c(n),a(m),dp(n,1e18);
        for(int i=0;i<n-1;i++)cin >> c[i];
        for(int i=0;i<m;i++)cin >> a[i];
        dp[0]=c[0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i+a[j]<n)dp[i+a[j]]=min(dp[i+a[j]],dp[i]+c[i+a[j]]);
            }
        }
        if(dp[n-1]==1e18)cout << "-1\n";
        else cout << dp[n-1] << '\n';
    }
}