#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<pair<int,int>> plates;
int dp[601][601];
int solve(int x,int y){
    if(dp[x][y]!=1e9)return dp[x][y];
    dp[x][y]=x*y;
    for(int i=0;i<n;i++){
        if(x==plates[i].first && y==plates[i].second)return dp[x][y]=0;
        if(plates[i].first<x)dp[x][y]=min(dp[x][y],solve(plates[i].first,y)+solve(x-plates[i].first,y));
        if(plates[i].second<y)dp[x][y]=min(dp[x][y],solve(x,plates[i].second)+solve(x,y-plates[i].second));
    }
    return dp[x][y];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int w,h;
    cin >> w >> h;
    for(int i=0;i<=w;i++)for(int j=0;j<=h;j++)dp[i][j]=1e9;
    cin >> n;
    plates.resize(n);
    for(int i=0;i<n;i++)cin >> plates[i].first >> plates[i].second;
    cout << solve(w,h);
}