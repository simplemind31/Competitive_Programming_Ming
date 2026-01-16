#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,tot,mini=1e18,fir[100000],sec[100000];;
pair<ll,ll> nums[100000];
vector<pair<ll,ll>> nue;
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    if(a.first==b.first)return a.first>b.first;
    return a.first<b.first;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);
    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> nums[i].first >> nums[i].second;
        fir[i]=nums[i].first;
        sec[i]=nums[i].second;
    }
    sort(fir,fir+n);
    sort(sec,sec+n);
    sort(nums,nums+n,cmp);
    nue.push_back(nums[0]);
    for(ll i=1;i<n;i++){
        if(nums[i].first<=nue.back().second)nue.back().second=max(nue.back().second,nums[i].second);
        else nue.push_back(nums[i]);
    }
    for(ll i=0;i<nue.size();i++)tot+=nue[i].second-nue[i].first;
    for(ll i=0;i<n;i++){
        ll iz=lower_bound(fir,fir+n,nums[i].first)-fir+1;
        ll de=upper_bound(sec,sec+n,nums[i].second)-sec-2;
        ll can=nums[i].second-nums[i].first;
        if(iz<n)can-=max(0LL,nums[i].second-fir[iz]);
        if(de>=0)can-=max(0LL,sec[de]-nums[i].first);
        mini=min(mini,max(can,0LL));
    }
    cout << tot-mini;
}