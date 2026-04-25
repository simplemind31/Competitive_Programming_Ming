#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("taming.in","r",stdin);
    freopen("taming.out","w",stdout);
    cin >> n;
    int nums[n],dp[n][n+1]; //dp[i][j]=the minimum of changes if there were j breakouts and the last one is in the position i
    // 0 is break out
    for(int i=0;i<n;i++){
        cin >> nums[i];
        con+=(nums[i]!=i);
        for(int j=0;j<=n;j++)dp[i][j]=1e9;
    }
    // the i-th breakout can only happen >= day i
    dp[0][1]=con;
    cout << con << '\n';
    for(int j=2;j<=n;j++){
        int mini=1e9;
        for(int i=j-1;i<n;i++){
            // el breakout j paso en el dia i
            for(int k=i-1;k>=0;k--){
                // el anterior paso en el dia k
                int temp=0;
                for(int l=i;l<n;l++){
                    if(nums[l]!=l-k)temp--;
                    if(nums[l]!=l-i)temp++;
                }
                dp[i][j]=min(dp[i][j],dp[k][j-1]+temp);
            }
            mini=min(mini,dp[i][j]);
        }
        cout << mini << '\n';
    }
}