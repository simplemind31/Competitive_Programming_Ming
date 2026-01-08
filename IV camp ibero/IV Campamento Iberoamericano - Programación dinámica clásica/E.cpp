#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,w;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> w;
    ll dp[n*1000+1];
    pair<int,int> nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i].first >> nums[i].second;
    }
    for(int i=0;i<=n*1000;i++)dp[i]=1e9+7;
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=n*1000;j>=0;j--){
            if(j-nums[i].second>=0)dp[j]=min(dp[j],dp[j-nums[i].second]+nums[i].first);
            else break;
        }
    }
    for(int i=n*1000;i>=0;i--){
        if(dp[i]<=w){
            cout << i;
            return 0;
        }
    }
}