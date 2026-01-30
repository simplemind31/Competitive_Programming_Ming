#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,l=-2e9,r=2e9;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    pair<ll,ll> nums[n];
    for(ll i=0;i<n;i++){
        cin >> nums[i].first >> nums[i].second;
    }
    while(l<r){
        ll mid=(l+r+1)>>1;
        ll con=0;
        for(ll i=0;i<n;i++){
            if(nums[i].first<mid)con+=min(mid-1,nums[i].second)-nums[i].first+1;
        }
        if(con<=k)l=mid;
        else r=mid-1;
    }
    cout << l;
}