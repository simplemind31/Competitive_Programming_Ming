#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int nums[n+2],psum[n+2];
        memset(psum,0,sizeof(psum));
        memset(nums,0,sizeof(nums));
        for(int i=1;i<=n;i++){
            cin >> nums[i];
        }
        ll res=0;
        for(int i=1;i<=n;i++){
            psum[i]+=psum[i-1];
            ll can=nums[i];
            res+=can;
            // rango entre i+1 al i+nums[i];
            nums[i]=min(nums[i],n-1-i);
            psum[i+1]+=can;
            psum[i+nums[i]+1]-=can;
        }
    }
}