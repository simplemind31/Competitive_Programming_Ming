#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    int nums[n+1],dp[n+1];
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        dp[i]=1e9;
    }
    dp[1]=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i-j>0)dp[i]=min(dp[i],dp[i-j]+abs(nums[i]-nums[i-j]));
        }
    }
    cout << dp[n];
}