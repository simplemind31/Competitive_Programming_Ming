#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
string st;
int dp[500][500];
int solve(int l,int r){
    if(dp[l][r]!=-1)return dp[l][r];
    if(r<l)return 0;
    dp[l][r]=1e9;
    for(int i=l+1;i<=r;i++)if(st[l]==st[i])dp[l][r]=min(dp[l][r],solve(l+1,i-1)+solve(i+1,r));
    dp[l][r]=min(dp[l][r],solve(l+1,r)+1);
    return dp[l][r];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin >> st;
    cout << solve(0,st.size()-1);
}