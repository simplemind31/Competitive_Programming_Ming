#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
ll c,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> c >> m;
        pair<pair<ll,ll>,ll> cows[n];
        for(int i=0;i<n;i++)cin >> cows[i].first.first >> cows[i].first.second >> cows[i].second;
        ll l=0,r=c+m-2;
        while(l<r){
            ll mid=(l+r)>>1;
            // use mid moonies
            ll x1=max(1ll,c-mid),x2=min(c+m-mid-1,c);
            for(int i=0;i<n && x1<=x2;i++){
                ll de=cows[i].second-cows[i].first.second*(c+m-mid);
                ll iz=cows[i].first.first-cows[i].first.second;
                if(iz==0){
                    if(cows[i].first.first*(c+m-mid)>cows[i].second)x2=-1e18;
                }else if(iz>0) x2=min(x2,de/iz);
                else x1=max(x1,(-de+cows[i].first.second-cows[i].first.first-1)/(-iz));
            }
            if(x1<=x2)r=mid;
            else l=mid+1;
        }
        cout << l << '\n';
    }
}