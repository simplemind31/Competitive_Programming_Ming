#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,m,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("socdist.in","r",stdin);
    freopen("socdist.out","w",stdout);
    cin >> n >> m;
    vector<pair<ll,ll>> nums(m);
    for(int i=0;i<m;i++){
        cin >> nums[i].first >> nums[i].second;
    }
    sort(nums.begin(),nums.end());
    ll l=1,r=1e18;
    while(l<r){
        vector<pair<ll,ll>> cop(nums);
        ll mid=(l+r+1)>>1;
        ll last=-1e18;
        ll con=0;
        for(int i=0;i<m && con<n;i++){
            cop[i].first=max(cop[i].first,last+mid);
            if(cop[i].first<=cop[i].second){
                con++;
                last=cop[i].first;
                i--;
            }
        }
        if(con>=n)l=mid;
        else r=mid-1;
    }
    cout << l;
}