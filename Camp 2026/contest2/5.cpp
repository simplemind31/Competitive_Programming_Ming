#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll dp[1000001],n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    vector<ll> nums(k);
    for(int i=0;i<k;i++)cin >> nums[i];
    nums.push_back(1e18);
    k++;
    sort(nums.begin(),nums.end());
    int last=0;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(i==nums[last]){
            last++;
            continue;
        }
        while(i>nums[last])last++;
        if(i==1)dp[i]=1;
        else dp[i]=(dp[i-1]+dp[i-2])%MOD;
    }
    cout << dp[n];
}