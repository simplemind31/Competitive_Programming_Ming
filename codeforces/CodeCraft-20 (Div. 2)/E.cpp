#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,p,k;
bool cmp(vector<int>& x,vector<int>& y){return x.back()>y.back();}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> p >> k;
    vector person(n+1,vector<int>(p+1));
    person[0][p]=1e9+7;
    for(int i=1;i<=n;i++)cin >> person[i][p];
    for(int i=1;i<=n;i++)for(int j=0;j<p;j++)cin >> person[i][j];
    sort(ALL(person),cmp);
    ll dp[n+1][1<<p];
    fill(&dp[0][0],&dp[0][0]+(n+1)*(1<<p),-1e18);
    dp[0][0]=0;
    // maxima cantidad de strength si considero los primeros n personas y mi subset posicion está elegida
    // la posicion 0 es dummy person
    for(int i=1;i<=n;i++){
        for(int mask=0;mask<(1<<p);mask++){
            dp[i][mask]=dp[i-1][mask];
            if(i-__builtin_popcount(mask)<=k)dp[i][mask]=max(dp[i][mask],dp[i-1][mask]+person[i][p]);
            for(int j=0;j<p;j++)if((mask&(1<<j)))dp[i][mask]=max(dp[i][mask],dp[i-1][mask^(1<<j)]+person[i][j]);
        }
    }
    cout << dp[n][(1<<p)-1];
}