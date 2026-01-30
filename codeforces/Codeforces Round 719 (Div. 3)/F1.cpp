#include<bits/stdc++.h>
using namespace std;
int n,t,ans,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> t;
    while(t--){
        int l=1,r=n;
        cin >> k;
        while(l<r){
            int mid=(l+r)>>1;
            cout << "? 1 " << mid << '\n';
            cout.flush();
            cin >> ans;
            if(mid-ans>=k)r=mid;
            else l=mid+1;
        }
        cout << "! " << l << '\n';
        cout.flush();
    }
}