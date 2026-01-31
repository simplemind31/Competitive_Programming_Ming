#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("cowdance.in","r",stdin);
    freopen("cowdance.out","w",stdout);
    cin >> n >> m;
    ll nums[n];
    for(ll i=0;i<n;i++){
        cin >> nums[i];
    }
    ll l=1,r=n;
    while(l<r){
        ll mid=(l+r)>>1;
        priority_queue<ll,vector<ll>,greater<ll>> ord;
        ll maxi=0;
        for(ll i=0;i<mid;i++){
            ord.push(nums[i]);
        }
        for(int i=mid;i<n;i++){
            ll top=ord.top();
            ord.pop();
            ord.push(top+nums[i]);
        }
        while(!ord.empty()){
            maxi=ord.top();
            ord.pop();
        }
        if(maxi<=m)r=mid;
        else l=mid+1;
    }
    cout << l;
}