#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,x,mat[16][16],dp[1<<16];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin >> mat[i][j];
    for(int i=0;i<(1<<n);i++){
        vector<int> nums;
        for(int j=0;j<n;j++)if(i&(1<<j))nums.push_back(j);
        for(int j=0;j<nums.size();j++)for(int k=j+1;k<nums.size();k++)dp[i]+=mat[nums[j]][nums[k]];
        for(int j=i&(i-1);j;j=(j-1)&i)dp[i]=max(dp[i],dp[j]+dp[i^j]);
    }
    cout << dp[(1<<n)-1];
}