#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,m,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("convention.in","r",stdin);
    freopen("convention.out","w",stdout);
    cin >> n >> m >> c;
    ll nums[n];
    for(ll i=0;i<n;i++){
        cin >> nums[i];
    }
    sort(nums,nums+n);
    ll l=0,r=1e9;
    while(l<r){
        ll mid=(l+r)>>1;
        int can=0;
        int last=0;
        for(int i=0;i<n;i++){
            if(nums[i]-nums[last]>mid || i-last+1>c){
                last=i;
                can++;
            }
        }
        can++;
        if(can<=m)r=mid;
        else l=mid+1;
    }
    cout << l;
}