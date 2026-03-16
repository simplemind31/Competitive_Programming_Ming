#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n;
ll dp[401][401],nums[401],psum[401];
ll solve(int l,int r){
    if(r<=l)return 0;
    if(dp[l][r]!=0)return dp[l][r];
    dp[l][r]=1e18;
    // de l a i y otro de i+1 a r y unir
    for(int j=l;j<=r;j++){
        dp[l][r]=min(dp[l][r],solve(l,j)+solve(j+1,r)+psum[r]-psum[l-1]);
    }
    return dp[l][r];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        psum[i]=psum[i-1]+nums[i];
    }
    cout << solve(1,n);
}