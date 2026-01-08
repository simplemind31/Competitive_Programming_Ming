#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<vector<int>> nums(n,vector<int>(3));
    vector<vector<int>> dp=nums;
    for(int i=0;i<n;i++){
        cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
    }
    dp[0][0]=nums[0][0];
    dp[0][1]=nums[0][1];
    dp[0][2]=nums[0][2];
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j==k)continue;
                dp[i][j]=max(dp[i][j],dp[i-1][k]+nums[i][j]);
            }
        }
    }
    cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}