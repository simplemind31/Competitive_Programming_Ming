#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,l,r=1e15;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> m >> n;
    pair<ll,pair<ll,ll>> nums[n];
    for(ll i=0;i<n;i++){
        cin >> nums[i].first >> nums[i].second.first >> nums[i].second.second;
    }
    while(l<r){
        ll mid=(l+r)>>1;
        ll con=0;
        for(int i=0;i<n;i++){
            ll aiz=0,ade=min(m,mid/nums[i].first);
            while(aiz<ade){
                ll amid=(aiz+ade+1)>>1;
                if(amid*nums[i].first+((ll)((amid-1)/nums[i].second.first))*nums[i].second.second<=mid)aiz=amid;
                else ade=amid-1;
            }
            con+=aiz;
        }
        if(con>=m)r=mid;
        else l=mid+1;
    }
    ll con=0;
    cout << l << '\n';
    for(int i=0;i<n;i++){
        ll aiz=0,ade=min(m,l/nums[i].first);
        while(aiz<ade){
            ll amid=(aiz+ade+1)>>1;
            if(amid*nums[i].first+((ll)((amid-1)/nums[i].second.first))*nums[i].second.second<=l)aiz=amid;
            else ade=amid-1;
        }
        if(con+aiz<=m){
            cout << aiz << ' ';
            con+=aiz;
        }else{
            cout << m-con << ' ';
            con=m;
        }
    }
}