#include <bits/stdc++.h>
using namespace std;
int n,t,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        int maxi=0;
        cin >> n >> k;
        int nums[n];
        for(int i=0;i<n;i++)cin >> nums[i];
        int l=0,r=2e8;
        while(l<r){
            int mid=(l+r+1)>>1;
            bool xd=false;
            for(int i=0;i<n && !xd;i++){
                int need=0;
                for(int j=i;j<n && need<=k;j++){
                    if(mid-(j-i)-nums[j]<=0)xd=true;
                    need+=mid-(j-i)-(nums[j]);
                }
            }
            if(xd)l=mid;
            else r=mid-1;
        }
        cout << l << '\n';
    }
}