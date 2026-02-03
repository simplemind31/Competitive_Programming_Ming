#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll j=0,nums[n],mini=n+1;
    vector<pair<ll,ll>> cont;//gcd, index
    for(int i=0;i<n;i++){
        cin >> nums[i];
        vector<pair<ll,ll>> nue;
        ll last=nums[i];
        nue.push_back({nums[i],i});
        for(auto p:cont){
            ll gc=gcd(nums[i],p.first);
            if(nue.back().first!=gc)nue.push_back({gc,p.second});
        }
        cont=nue;
        if(cont.back().first==1)mini=min(mini,i-cont.back().second+1);
    }
    if(mini==n+1)mini=-1;
    cout << mini;
}