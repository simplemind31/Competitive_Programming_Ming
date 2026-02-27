#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int nums[n];
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        int l=0,r=n/2;
        while(l<r){
            int mid=(l+r)>>1;
            //usar mid operations
            // 1 al mid, n-mid+1 al n
            int last=-1;
            bool xd=true;
            for(int i=0;i<n && xd;i++){
                if(nums[i]>mid && nums[i]<n-mid+1){
                    if(nums[i]<last){
                        xd=false;
                    }
                    last=nums[i];
                }
            }
            if(xd)r=mid;
            else l=mid+1;
        }
        cout << l << '\n';
    }
}