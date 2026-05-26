#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ll nums[n+2],psum[n+2],ssum[n+2];
        psum[0]=ssum[n+1]=nums[0]=nums[n+1]=0;
        vector<int> res;
        int bestpos=n;
        for(int i=1;i<=n;i++){
            cin >> nums[i];
            psum[i]=psum[i-1]+abs(nums[i]);
        }
        for(int i=n-1;i>=1;i--){
            ssum[i]=ssum[i+1]+((nums[i]>0)?nums[i]:0);
            if(ssum[i+1]+psum[i-1]>=ssum[bestpos+1]+psum[bestpos-1])bestpos=i;
        }
        cout << res.size() << '\n';
        for(auto u:res)cout << u << ' ';
        cout << '\n';
    }
}