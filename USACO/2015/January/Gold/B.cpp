#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,l,a,mini=1e9;
vector<int> duration;
vector<vector<int>> movies;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("movie.in","r",stdin);
    freopen("movie.out","w",stdout);
    cin >> n >> l;
    movies.resize(n);
    duration.resize(n);
    for(int i=0;i<n;i++){
        cin >> duration[i] >> a;
        movies[i].resize(a);
        for(int j=0;j<a;j++)cin >> movies[i][j];
        sort(ALL(movies[i]));
    }
    ll dp[1<<n];//dp[mask]=el tiempo máximo de seguidos solo ven el subeset, es decir [0,x]
    memset(dp,0,sizeof(dp));
    for(int mask=1;mask<(1<<n);mask++){
        if(__builtin_popcount(mask)>=mini)continue;
        for(int i=0;i<n;i++){
            if(!(mask&(1<<i)))continue;
            // llegué a dp[mask^(1<<i)] segundos, ahora extender 
            int pos=upper_bound(ALL(movies[i]),dp[mask^(1<<i)])-movies[i].begin()-1;
            if(pos==-1)continue;
            dp[mask]=max(dp[mask],0ll+movies[i][pos]+duration[i]);
            if(dp[mask]>=l){
                mini=__builtin_popcount(mask);
                break;
            }
        }
    }
    if(mini==1e9)mini=-1;
    cout << mini;
}