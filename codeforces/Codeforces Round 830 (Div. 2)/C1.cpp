#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,q,l,r,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> q;
        ll psum[n+1],pxor[n+1];
        psum[0]=pxor[0]=0;
        for(int i=1;i<=n;i++){
            cin >> a;
            psum[i]=psum[i-1]+a;
            pxor[i]=pxor[i-1]^a;
        }
        while(q--){
            cin >> l >> r;
            ll need=psum[r]-psum[l-1]-(pxor[r]^pxor[l-1]);
            int l=1,r=n;
            while(l<r){
                int mid=(l+r)>>1;
                bool xd=false;
                for(int i=mid;i<=n && !xd;i++){
                    if(psum[i]-psum[i-mid]-(pxor[i]^pxor[i-mid])==need)xd=true;
                }
                if(xd)r=mid;
                else l=mid+1;
            }
            for(int i=l;i<=n;i++){
                if(psum[i]-psum[i-l]-(pxor[i]^pxor[i-l])==need){
                    cout << i-l+1 << ' ' << i << '\n';
                    break;
                }
            }
        }
    }
}