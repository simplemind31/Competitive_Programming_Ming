#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
char c;
int jo,b;
int dist(pair<int,int> a,pair<int,int> b){return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("radio.in","r",stdin);
    freopen("radio.out","w",stdout);
    cin >> jo >> b;
    pair<int,int> john[jo+1],bessie[b+1];
    cin >> john[0].first >> john[0].second;
    cin >> bessie[0].first >> bessie[0].second;
    for(int i=1;i<=jo;i++){
        cin >> c;
        john[i]=john[i-1];
        if(c=='N')john[i].second++;
        else if(c=='S')john[i].second--;
        else if(c=='E')john[i].first++;
        else john[i].first--;
    }
    for(int i=1;i<=b;i++){
        cin >> c;
        bessie[i]=bessie[i-1];
        if(c=='N')bessie[i].second++;
        else if(c=='S')bessie[i].second--;
        else if(c=='E')bessie[i].first++;
        else bessie[i].first--;
    }
    ll dp[jo+1][b+1];
    fill(&dp[0][0],&dp[0][0]+(jo+1)*(b+1),1e18);
    dp[0][0]=0;
    for(int i=0;i<=jo;i++){
        for(int j=0;j<=b;j++){
            if(i)dp[i][j]=min(dp[i][j],dp[i-1][j]+dist(john[i],bessie[j]));
            if(j)dp[i][j]=min(dp[i][j],dp[i][j-1]+dist(john[i],bessie[j]));
            if(i&&j)dp[i][j]=min(dp[i][j],dp[i-1][j-1]+dist(john[i],bessie[j]));
        }
    }
    cout << dp[jo][b];
}