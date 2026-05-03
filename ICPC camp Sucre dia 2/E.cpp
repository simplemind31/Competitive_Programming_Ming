#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,sum;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll c[n],p[n];
    for(int i=0;i<n;i++)cin >> c[i];
    for(int i=0;i<n;i++){
        cin >> p[i];
        sum+=p[i];
    }
    ll l=0,r=1e14;
    while(l<r){
        ll mid=(l+r+1)>>1;
        ll need=0;
        for(int i=n-1;i>=0 && need<=sum;i--){
            if(log10(c[i])+log10(mid)>=15){
                need=1;
                break;
            }
            need+=c[i]*mid;
            need=max(0ll,need-p[i]);
        }
        if(need==0)l=mid;
        else r=mid-1;
    }
    cout << l;
}