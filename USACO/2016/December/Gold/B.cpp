#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int h,g;
int dist(pair<int,int> a,pair<int,int> b){return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("checklist.in","r",stdin);
    freopen("checklist.out","w",stdout);
    cin >> h >> g;
    pair<int,int> holstein[h+1],guernsey[g+1];
    for(int i=1;i<=h;i++)cin >> holstein[i].first >> holstein[i].second;
    for(int i=1;i<=g;i++)cin >> guernsey[i].first >> guernsey[i].second;
    ll dp[h+1][g+1][2];// minimo distancia si tengo los primeros h y g y el ultimo en usar fue 0->h,1->g
    fill(&dp[0][0][0],&dp[0][0][0]+(h+1)*(g+1)*2,1e18);
    dp[1][0][0]=0;
    for(int i=1;i<=h;i++){
        for(int j=0;j<=g;j++){
            dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][0]+dist(holstein[i-1],holstein[i]));
            dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][1]+dist(guernsey[j],holstein[i]));
            if(j)dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+dist(holstein[i],guernsey[j]));
            if(j)dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+dist(guernsey[j-1],guernsey[j]));
        }
    }
    cout << dp[h][g][0];
}