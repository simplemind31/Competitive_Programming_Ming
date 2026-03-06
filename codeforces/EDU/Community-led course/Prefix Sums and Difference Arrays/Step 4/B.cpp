#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,q,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<ll> nums(n+5);
    for(ll i=2;i<=n+1;i++){
        cin >> nums[i];
    }
    for(ll i=n+2;i>=1;i--){
        nums[i]=nums[i]-nums[i-1];
    }
    for(ll i=n+2;i>=1;i--){
        nums[i]=nums[i]-nums[i-1];
    }
    cin >> q;
    /*
    // b[l]...b[r]

    d[i]+=step for i in [l, r]

    dd[l]+=step
    dd[r+1]-=step;

    d[r+1]-=(r-l+1)*step

    dd[r+1]-=(r-l+1)*step
    dd[r+2]+=(r-l+1)*step
    */
    while(q--){
        cin >> a >> b >> c;
        nums[a+1]+=c;
        nums[b+2]-=c;
        nums[b+2]-=(b-a+1)*c;
        nums[b+3]+=(b-a+1)*c;
    }
    for(ll i=1;i<=n+2;i++){
        nums[i]+=nums[i-1];
    }
    for(ll i=1;i<=n+2;i++){
        nums[i]+=nums[i-1];
    }
    for(ll i=2;i<=n+1;i++){
        cout << nums[i] << ' ';
    }
}