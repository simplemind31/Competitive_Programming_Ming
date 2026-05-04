#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef long double ld;
const ld PI=acos(-1.0);
int n;
ld l,r;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> l >> r;
    r-=l;
    pair<pair<ld,ld>,ld> light[n];
    for(int i=0;i<n;i++){
        cin >> light[i].first.first >> light[i].first.second >> light[i].second;
        light[i].first.first-=l;
        light[i].second=light[i].second*PI/180.0;
    }
    ld dp[1<<n];
    memset(dp,0,sizeof(dp));
    for(int mask=1;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(!(mask&(1<<i))) continue;
            ld a=dp[mask^(1<<i)];
            ld ang1=atan2(a-light[i].first.first,light[i].first.second);
            ld next_ang1=ang1+light[i].second;
            ld L;
            if(next_ang1>=PI/2.0)L=r;
            else L=light[i].first.first+light[i].first.second*tan(next_ang1);
            dp[mask]=max(dp[mask],L);
        }
        dp[mask]=min(dp[mask],r);
    }
    cout << fixed << setprecision(9) << dp[(1<<n)-1];
}