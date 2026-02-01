#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> q;
    while(q--){
        cin >> n;
        if(n<6){
            cout << n-1 << '\n';
            continue;
        }
        if(n<=8){
            cout << n << '\n';
            continue;
        }
        ll l=3,r=n/2;
        while(l<r){
            // maximizar non-bridge
            ll mid=(l+r)>>1;
            // hay n-mid bridge
            ll de=mid*(mid-1)/2;
            // puede haber entre mid...de non-bridge
            if(n-mid>de){
                // puede haber mas non-bridge
                l=mid+1;
            }else{
                r=mid;
            }
        }
        ll op1=n-l+min(l*(l-1)/2,n-l),op2=0,op3=0;
        l++;
        if(n-l>=l && l>=3)op2=n-l+min(l*(l-1)/2,n-l);
        l-=2;
        if(n-l>=l && l>=3)op3=n-l+min(l*(l-1)/2,n-l);
        cout << max({op1,op2,op3}) << '\n';
    }
}