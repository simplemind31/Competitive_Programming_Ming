#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
//const ll raiz=448;
ll n,q,a,b,c;
ll dp[501];
bool cmp(pair<pair<ll,ll>,pair<ll,ll>> a,pair<pair<ll,ll>,pair<ll,ll>> b){
    if(a.first.second==b.first.second)return a.first.first<=b.first.first;
    return a.first.second<b.first.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll raiz=500;
    vector<pair<ll,ll>> nums(n);
    // peso satisfaccion
    for(ll i=0;i<n;i++)cin >> nums[i].first >> nums[i].second;
    cin >> q;
    vector<ll> res(q);
    vector<pair<pair<ll,ll>,pair<ll,ll>>> blocks[raiz+1];
    for(ll i=0;i<q;i++){
        cin >> a >> b >> c;
        a--;b--;
        vector<ll> res(501);
        for(int j=a;j<=b;j++){
            for(int k=500;k>=nums[j].first;k--){
                res[k]=max(res[k],res[k-nums[j].first]+nums[j].second);
            }
        }
        cout << res[c] << '\n';
        blocks[a/raiz].push_back({{a,b},{c,i}});
    }
    return 0;
    for(ll i=0;i<=raiz;i++){
        sort(ALL(blocks[i]),cmp);
        ll last=(i+1)*raiz-1;
        for(auto u:blocks[i]){
            if(u.first.second/raiz==i){
                // dentro del block
                for(ll j=u.first.first;j<=u.first.second;j++){
                    for(ll k=500;k>=nums[j].first;k--){
                        dp[k]=max(dp[k],dp[k-nums[j].first]+nums[j].second);
                    }
                }
                res[u.second.second]=dp[u.second.first];
                for(ll k=500;k>=0;k--)dp[k]=0;
                continue;
            }
            while(last<u.first.second){
                last++;
                for(ll k=500;k>=nums[last].first;k--){
                    dp[k]=max(dp[k],dp[k-nums[last].first]+nums[last].second);
                }
            }
            ll temp[501];
            for(ll k=500;k>=0;k--)temp[k]=dp[k];
            for(ll j=(i+1)*raiz-1;j>=u.first.first;j--){
                for(ll k=500;k>=nums[j].first;k--){
                    dp[k]=max(dp[k],dp[k-nums[j].first]+nums[j].second);
                }
            }
            ll maxi=0;
            res[u.second.second]=dp[u.second.first];
            for(ll k=500;k>=0;k--)dp[k]=temp[k];
        }
        for(ll k=500;k>=0;k--)dp[k]=0;
    }
    for(ll i=0;i<q;i++){
        cout << res[i] << '\n';
    }
}