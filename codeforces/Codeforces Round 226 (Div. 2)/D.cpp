#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
ld l,r;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> l >> r;
    pair<pair<ld,ld>,ld> light[n];
    ld dp[1<<n];// maximo length si tengo subset
    fill(dp,dp+(1<<n),l);
    for(int mask=1;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(!(mask&(1<<i)))continue;
            // i fue el ultimo
            ld ante=dp[mask^(1<<i)];
            ld tanab=light[i].second/(ante-light[i].first);
            // a partir de ante
        }
    }
    cout << dp[(1<<n)-1];
}
