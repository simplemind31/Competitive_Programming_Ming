#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int ne[200001];
int find(int a){return(ne[a]==a)?a:ne[a]=find(ne[a]);}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll a[n],d[n];
    pair<pair<ll,ll>,ll> nums[n];
    for(ll i=0;i<n;i++)cin >> a[i];
    for(ll i=0;i<n;i++){
        cin >> d[i];
        nums[i]={{max(i-d[i],0ll),min(i+d[i],n-1)},a[i]};
    }
    sort(nums,nums+n);
    ll l=0,r=1e15;
    while(l<r){
        ll mid=(l+r)>>1;
        // ninguno pasa de mid
        vector<ll> cant(n);
        for(int i=0;i<=n;i++)ne[i]=i;
        priority_queue<pair<pair<ll,ll>,ll>,vector<pair<pair<ll,ll>,ll>>,greater<pair<pair<ll,ll>,ll>>> ayu;
        for(int i=0;i<n;i++)ayu.push(make_pair(make_pair(nums[i].first.second,nums[i].first.first),nums[i].second));
        bool xd=true;
        while(!ayu.empty()){
            pair<pair<ll,ll>,ll> top=ayu.top();
            ayu.pop();
            int iz=top.first.second;
            int de=top.first.first;
            int c=top.second;
            while(c){
                iz=find(iz);
                if(iz>de){
                    xd=false;
                    break;
                }
                if(cant[iz]+c<mid){
                    cant[iz]+=c;
                    c=0;
                }else{
                    c-=mid-cant[iz];
                    cant[iz]=mid;
                    ne[iz]=iz+1;
                }
            }
        }
        if(xd)r=mid;
        else l=mid+1;
    }
    cout << l;
}