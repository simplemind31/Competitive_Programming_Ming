#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
long double m;
int square(int a){return a*a;}
const pair<int,int> origen={0,0};
long double dist(pair<int,int> a,pair<int,int> b){
    return sqrtl(square(a.first-b.first)+square(a.second-b.second));
}
long double bigmod(long double b,int e){
    long double p=1;
    for(;e;e>>=1,b*=b)if(e&1)p*=b;
    return p;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    pair<pair<int,int>,int> mice[n];
    for(int i=0;i<n;i++)cin >> mice[i].first.first >> mice[i].first.second >> mice[i].second;
    long double l=0,r=1e18;
    cin >> m;
    while(abs(r-l)>=1e-3){
        long double mid=(l+r)/2;
        long double dp[1<<n][n];
        // el timpiempo minimo para capturar el subset y terminar en la posicion i, mi velocidad=pow(m,_builtin)
        fill(&dp[0][0],&dp[0][0]+(1<<n)*n,1e18);
        for(int mask=1;mask<(1<<n);mask++){
            for(int i=0;i<n;i++){
                if(!(mask&(1<<i)))continue;
                if(__builtin_popcount(mask)==1){
                    long double tiempo=dist(origen,mice[i].first)/mid;
                    if(tiempo<=mice[i].second)dp[mask][i]=tiempo;
                    continue;
                }
                for(int j=0;j<n;j++){
                    if(!(mask&(1<<j)))continue;
                    // llegue del j al i
                    //if(dp[mask^(1<<i)][j]==1e18)continue;
                    long double tiempo=dp[mask^(1<<i)][j]+dist(mice[j].first,mice[i].first)/(mid*bigmod(m,__builtin_popcount(mask)-1));
                    if(tiempo<=mice[i].second)dp[mask][i]=min(dp[mask][i],tiempo);
                }
            }
        }
        long double mini=1e18;
        for(int i=0;i<n;i++)mini=min(mini,dp[(1<<n)-1][i]);
        if(mini==1e18)l=mid;
        else r=mid;
    }
    cout << fixed << setprecision(3) << l;
}