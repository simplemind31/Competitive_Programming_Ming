#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,w;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> w;
    ll dp[w+1];
    pair<int,int> nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i].first >> nums[i].second;
    }
    for(int i=0;i<=w;i++)dp[i]=0;
    for(int i=0;i<n;i++){
        for(int j=w;j>=0;j--){
            if(j-nums[i].first>=0)dp[j]=max(dp[j],dp[j-nums[i].first]+nums[i].second);
            else break;
        }
    }
    cout << dp[w];
}