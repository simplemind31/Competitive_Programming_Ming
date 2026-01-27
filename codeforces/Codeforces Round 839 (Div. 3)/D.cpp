#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n,k;
string st;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        int nums[n];
        int l=0,r=1e9;
        for(int i=0;i<n;i++)cin >> nums[i];
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i])continue;
            if(nums[i-1]<nums[i])r=min(r,(nums[i-1]+nums[i])>>1);
            else l=max(l,(nums[i-1]+nums[i]-1)/2+1);
        }
        if(l<=r)cout << l << '\n';
        else cout << -1 << '\n';
    }
}