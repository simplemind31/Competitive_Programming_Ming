#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,mini;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    ll nums[n];
    for(ll i=0;i<n;i++)cin >> nums[i];
    sort(nums,nums+n);
    vector<pair<ll,ll>> nue;
    nue.push_back({nums[0],1});
    for(ll i=1;i<n;i++){
        if(nums[i]==nums[i-1])nue.back().second++;
        else nue.push_back({nums[i],1});
    }
    ll iz=0,de=nue.size()-1;
    while(iz<de && k){
        if(nue[iz].second<nue[de].second){
            // reducir iz;
            // cada nue[iz].second reduce 1
            ll can=nue[iz+1].first-nue[iz].first;
            if(k>=can*nue[iz].second){
                k-=can*nue[iz].second;
                nue[iz+1].second+=nue[iz].second;
                iz++;
            }else{
                //lo que alcance
                ll canredu=k/nue[iz].second;
                nue[iz].first+=canredu;
                k=0;
            }
        }else{
            //reducir de;
            ll can=nue[de].first-nue[de-1].first;
            if(k>=can*nue[de].second){
                k-=can*nue[de].second;
                nue[de-1].second+=nue[de].second;
                de--;
            }else{
                //lo que alcance
                ll canredu=k/nue[de].second;
                nue[de].first-=canredu;
                k=0;
            }
        }
    }
    mini=nue[de].first-nue[iz].first;
    cout << mini;
}