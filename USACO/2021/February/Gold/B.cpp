#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,dp[300][300],a;
vector<int> nums;
int solve(int l,int r){
    if(r<l)return 0;
    if(l==r)return 1;
    if(dp[l][r]!=-1)return dp[l][r];
    dp[l][r]=1e9;
    for(int i=l;i<r;i++){
        dp[l][r]=min(dp[l][r],solve(l,i)+solve(i+1,r)-(nums[l]==nums[r]));
    }
    return dp[l][r];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin >> n >> a;
    nums.push_back(a);
    for(int i=1;i<n;i++){
        cin >> a;
        if(a!=nums.back())nums.push_back(a);
    }
    n=nums.size();
    cout << solve(0,n-1);
}
// 1 2 1 3 1 4 1 5 1