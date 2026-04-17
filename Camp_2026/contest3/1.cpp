#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,k,res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    int psum[n+2],ssum[n+2],nums[n+2];
    memset(psum,0,sizeof(psum));
    memset(ssum,0,sizeof(ssum));
    nums[0]=nums[n+1]=0;
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        if(nums[i]<nums[i-1])psum[i]=1;
        else psum[i]=psum[i-1]+1;
        res=max(res,psum[i]);
    }
    for(int i=n;i>=1;i--){
        if(nums[i]>nums[i+1])ssum[i]=1;
        else ssum[i]=ssum[i+1]+1;
    }
    for(int i=0;i+k+1<=n+1;i++)if(nums[i]<=nums[i+k+1])res=max(res,psum[i]+ssum[i+k+1]);
    cout << res;
}