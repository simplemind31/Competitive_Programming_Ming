#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<long long> vll;
typedef pair<ll,ll> pii;
typedef pair<long long,long long> pll;
ll n,t=1,ax,ay,bx,by;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> ax >> ay >> bx >> by;
        vector<pair<ll,pair<ll,ll>>> posi;
        pair<ll,ll> nums[n];
        for(ll i=0;i<n;i++){
            cin >> nums[i].first;
        }
        for(ll i=0;i<n;i++){
            cin >> nums[i].second;
        }
        sort(nums,nums+n);
        posi.push_back({nums[0].first,{nums[0].second,nums[0].second}});
        for(ll i=1;i<n;i++){
            if(nums[i].first==nums[i-1].first){
                posi.back().second.first=min(posi.back().second.first,nums[i].second);
                posi.back().second.second=max(posi.back().second.second,nums[i].second);
            }else{
                posi.push_back({nums[i].first,{nums[i].second,nums[i].second}});
            }
        }
        posi.push_back({bx,{by,by}});
        /*for(auto u:posi){
            cout << u.first << ' ' << u.second.first << ' ' << u.second.second << '\n';
        }
        cout << '\n';*/
        n=posi.size();
        vector<vector<ll>> dp(n,vector<ll>(2,1e18));
        // termino fila i, en iz o de;
        // teminar en mini
        dp[0][0]=posi[0].first-ax+abs(posi[0].second.second-ay)+(posi[0].second.second-posi[0].second.first);
        dp[0][1]=posi[0].first-ax+abs(posi[0].second.first-ay)+(posi[0].second.second-posi[0].second.first);
        //cout << dp[0][0] << ' ' << dp[0][1] << '\n';
        for(ll i=1;i<n;i++){
            ll op1=dp[i-1][0]+abs(posi[i].second.second-posi[i-1].second.first);
            ll op2=dp[i-1][1]+abs(posi[i].second.second-posi[i-1].second.second);
            dp[i][0]=min(dp[i][0],posi[i].first-posi[i-1].first+min(op1,op2)+posi[i].second.second-posi[i].second.first);
            op1=dp[i-1][0]+abs(posi[i].second.first-posi[i-1].second.first);
            op2=dp[i-1][1]+abs(posi[i].second.first-posi[i-1].second.second);
            dp[i][1]=min(dp[i][1],posi[i].first-posi[i-1].first+min(op1,op2)+posi[i].second.second-posi[i].second.first);
            //cout << dp[i][0] << ' ' << dp[i][1] << '\n';
        }
        cout << dp.back()[0] << '\n';
    }
}