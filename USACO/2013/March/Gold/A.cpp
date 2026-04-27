#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("cowrun.in","r",stdin);
    freopen("cowrun.out","w",stdout);
    cin >> n;
    ll nums[n+1];
    for(int i=0;i<n;i++)cin >> nums[i];
    nums[n]=0;
    sort(nums,nums+n+1);
    int pos0=lower_bound(nums,nums+n+1,0)-nums;
    ll dp[n+1][n+1][2];// el minimo costo para cubrir el rango pos0-i,pos0+j y teminar en pos0-i if k=0 o pos0+j if k=1. y el tiempo minimo para lograr eso 
    fill(&dp[0][0][0],&dp[0][0][0]+(n+1)*(n+1)*2,1e18);
    dp[pos0][pos0][0]=dp[pos0][pos0][1]=0;
    for(int i=0;i<=pos0;i++){
        for(int j=0;j<=n-pos0;j++){
            if(i)dp[pos0-i][pos0+j][0]=min(dp[pos0-i+1][pos0+j][0]+abs(nums[pos0-i+1]-nums[pos0-i])*(pos0-i+1+n-(pos0+j)),dp[pos0-i+1][pos0+j][1]+abs(nums[pos0+j]-nums[pos0-i])*(pos0-i+1+n-(pos0+j)));
            if(j)dp[pos0-i][pos0+j][1]=min(dp[pos0-i][pos0+j-1][0]+abs(nums[pos0-i]-nums[pos0+j])*(pos0-i+n-(pos0+j)+1),dp[pos0-i][pos0+j-1][1]+abs(nums[pos0+j-1]-nums[pos0+j])*(pos0-i+n-(pos0+j)+1));
        }
    }
    cout << min(dp[0][n][0],dp[0][n][1]);
}