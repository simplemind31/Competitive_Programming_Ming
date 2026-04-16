#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[3000][3000],suma,nums[3000];
// dp[i][j]=best rango(i,j);
ll solve(int l, int r){
    if(dp[l][r]!=1e18)return dp[l][r];
    if(l==r){
        if((r-l+1)%2==n%2)return dp[l][r]=nums[l];
        else return dp[l][r]=0;
    }
    // ((r-l+1)%2==n%2) => turno de Taro
    if((r-l+1)%2==n%2)return dp[l][r]=max(nums[l]+solve(l+1,r),solve(l,r-1)+nums[r]);
    else return dp[l][r]=min(solve(l+1,r),solve(l,r-1));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // Taro empieza maximiza X-Y.
    // X+Y=suma
    // X-Y=X-(suma-X)
    // = 2X-suma
    // entonces taro max X y jil min X;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        suma+=nums[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            dp[i][j]=1e18;
        }
    }
    cout << 2*solve(0,n-1)-suma;
}