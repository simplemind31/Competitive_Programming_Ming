#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int nums[n+1]={0},cop[n],dp[n+1],median;// maxima cantidad hasta pos i
        fill(dp,dp+n+1,-1e9);
        dp[0]=0;
        for(int i=0;i<n;i++){
            cin >> nums[i+1];
            cop[i]=nums[i+1];
        }
        sort(cop,cop+n);
        median=cop[n/2];
        for(int i=1;i<=n;i++){
            int suma=0,con=0;
            for(int j=i;j>0;j--){
                if(nums[j]>median)suma++;
                else if(nums[j]<median)suma--;
                else con++;
                if(((i-j+1)&1) && con>abs(suma))dp[i]=max(dp[i],dp[j-1]+1);
            }
        }
        cout << dp[n] << '\n';
    }
}