#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,t,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<ll> nums(n),maxiz(n),maxde(n),ori(n);
        for(ll i=0;i<n;i++){
            cin >> nums[i];
            ori[i]=nums[i];
        }
        maxiz[0]=nums[0];
        maxde[n-1]=nums[n-1];
        for(ll i=1;i<n;i++)maxiz[i]=max(maxiz[i-1],nums[i]);
        for(ll i=n-2;i>=0;i--)maxde[i]=max(maxde[i+1],nums[i]);
        for(ll i=0;i<n;i++)nums[i]=min(maxiz[i],maxde[i]);
        // resolver cada rango que tienen igual catidad
        vector<pair<ll,ll>> rangos;
        rangos.push_back({0,0});
        for(ll i=1;i<n;i++){
            if(nums[i]==nums[i-1])rangos.back().second=i;
            else rangos.push_back({i,i});
        }
        ll res=0;
        for(auto u:rangos){
            ll m=u.second-u.first+1;
            if(k==1){
                vector<vector<ll>> dp(m+1,vector<ll>(2,1e18));
                dp[0][0]=dp[0][1]=0;
                for(int i=1;i<=m;i++){
                    // tapo el actual
                    dp[i][1]=min(dp[i-1][1],dp[i-1][0])+nums[i+u.first-1]-ori[i+u.first-1];
                    // no tapo
                    if(nums[i+u.first-1]!=ori[i+u.first-1])dp[i][0]=dp[i-1][1]+nums[i+u.first-1]-ori[i+u.first-1]-1;
                }
                res+=min(dp[m][0],dp[m][1]);
                continue;
            }
            vector<ll> dp(m+1,1e18);
            dp[0]=0;
            for(int i=1;i<=m;i++){
                // para resolver i
                ll now=0;
                for(int j=i;j>=1;j--){
                    // tapo en el j
                    dp[i]=min(dp[i],dp[j-1]+nums[j+u.first-1]-ori[j+u.first-1]+max(0ll,now-k));
                    now+=nums[j+u.first-1]-ori[j+u.first-1];
                }
                dp[i]=min(dp[i],max(now-k,0ll));
            }
            res+=dp[m];
        }
        cout << res << '\n';
    }
}
/*
3
5 5
4 0 2 5 0
9 6
5 3 0 1 8 1 5 1 7
9 1
5 0 0 0 5 0 5 0 5


1
7
21
*/