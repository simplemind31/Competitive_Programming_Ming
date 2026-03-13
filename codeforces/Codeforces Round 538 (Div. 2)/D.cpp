#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,last[5000][5000],dp[5000][5000];
vector<int> nums;
int solve(int l,int r){
    if(r-l+1<=1)return 0;
    if(dp[l][r]!=0)return dp[l][r];
    dp[l][r]=1e9;
    // combinar l con uno del mismo color
    /*
    resolver primero lo de adentro, +solve
    luego cambiar el color de adentro a color de l +1
    todo al lado derecho tendremos que igualar +r-last[0][r][nums[l]]
    */
    dp[l][r]=min(dp[l][r],solve(l+1,last[r][nums[l]]-1)+r-last[r][nums[l]]+1);
    // no combinar l
    dp[l][r]=min(dp[l][r],solve(l+1,r)+1);
    return dp[l][r];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> a;
    a--;
    nums.push_back(a);
    for(int i=1;i<n;i++){
        cin >> a;a--;
        if(a!=nums.back())nums.push_back(a);
    }
    n=nums.size();
    last[0][nums[0]]=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<5000;j++){
            last[i][j]=last[i-1][j];
        }
        last[i][nums[i]]=i;
    }
    cout << solve(0,n-1);
}