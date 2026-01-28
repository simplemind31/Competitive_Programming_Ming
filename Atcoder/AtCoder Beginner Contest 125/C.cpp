#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n+2],psum[n+2],ssum[n+2];
    psum[0]=nums[0]=nums[n+1]=ssum[n+1]=0;
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        psum[i]=gcd(nums[i],psum[i-1]);
    }
    for(int i=n;i>=1;i--){
        ssum[i]=gcd(ssum[i+1],nums[i]);
        maxi=max(maxi,gcd(psum[i-1],ssum[i+1]));
    }
    cout << maxi;
}