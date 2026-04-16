#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
#define MOD 1000000007
int dp[100001],n,k;
vector<pair<int,int>> nums;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    nums.resize(n);
    for(int i=0;i<n;i++)cin >> nums[i].first;
    for(int i=0;i<n;i++)cin >> nums[i].second;
    for(int i=0;i<n;i++){
        for(int j=100000;j>=nums[i].first;j--){
            dp[j]=max(dp[j],dp[j-nums[i].first]+nums[i].second);
        }
    }
    cout << dp[k];
}