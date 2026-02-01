#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,con[800005],res[400005];
set<ll> dif;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    pair<ll,ll> nums[n];
    for(ll i=0;i<n;i++){
        cin >> nums[i].first >> nums[i].second;
        dif.insert(nums[i].first);
        dif.insert(nums[i].second);
        dif.insert(nums[i].first-1);
    }
    vector<ll> nuedif=vector(ALL(dif));
    for(ll i=0;i<n;i++){
        con[lower_bound(ALL(nuedif),nums[i].first)-nuedif.begin()]++;
        con[lower_bound(ALL(nuedif),nums[i].second)-nuedif.begin()+1]--;
    }
    res[con[0]]+=nuedif[0];
    for(ll i=1;i<nuedif.size();i++){
        con[i]+=con[i-1];
        res[con[i]]+=nuedif[i]-nuedif[i-1];
    }
    for(ll i=1;i<=n;i++){
        cout << res[i] << ' ';
    }
}