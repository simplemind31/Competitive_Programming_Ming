#include <bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> nums[n];
    int dp[n][2];
    //maxima cantidas hasta i si usaré i+1 antes que i;
    for(int i=0;i<n;i++){
        nums[i]={0,0,0};
        for(int j=0;j<2;j++)dp[i][j]=0;
    }
    for(int i=0;i<n;i++)cin >> nums[i][0];
    for(int i=0;i<n;i++)cin >> nums[i][1];
    for(int i=0;i<n;i++)cin >> nums[i][2];
    dp[0][0]=nums[0][0];
    dp[0][1]=nums[0][1];
    for(int i=1;i<n;i++){
        dp[i][0]=max(dp[i-1][0]+nums[i][1],dp[i-1][1]+nums[i][0]);
        dp[i][1]=max(dp[i-1][0]+nums[i][2],dp[i-1][1]+nums[i][1]);
    }
    cout << dp[n-1][0];
}