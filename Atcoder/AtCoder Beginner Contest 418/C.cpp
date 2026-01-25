#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    ll nums[n],psum[n];
    for(ll i=0;i<n;i++){
        cin >> nums[i];
    }
    sort(nums,nums+n);
    psum[0]=nums[0];
    for(ll i=1;i<n;i++){
        psum[i]=psum[i-1]+nums[i];
    }
    while(q--){
        cin >> a;
        if(a>nums[n-1]){
            cout << -1 << '\n';
            continue;
        }
        int pos=lower_bound(nums,nums+n,a)-nums;
        //sumar a la iz;
        ll suma=0;
        if(pos)suma+=psum[pos-1];
        suma+=(n-pos)*(a-1)+1;
        cout << suma << '\n';
    }
}