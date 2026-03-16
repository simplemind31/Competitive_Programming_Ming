#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
int n,k,nums[100],dp[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++)cin >> nums[i];
    for(int i=0;i<=k;i++){
        if(dp[i]==1)continue;
        for(int j=0;j<n && i+nums[j]<=k;j++)dp[i+nums[j]]=1;
    }
    cout << (dp[k]?"First":"Second");
}