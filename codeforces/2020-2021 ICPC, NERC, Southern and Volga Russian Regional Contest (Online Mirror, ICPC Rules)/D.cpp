#include <bits/stdc++.h>
using namespace std;
int t,n,a,b,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m >> a >> b;
        if(a>b){
            a=n-a+1;
            b=n-b+1;
        }
        int nums[m];
        for(int i=0;i<m;i++){
            cin >> nums[i];
        }
        sort(nums,nums+m);
        int l=0,r=m;
        while(l<r){
            int mid=(l+r+1)>>1;
            bool xd=true;
            for(int i=mid-1;i>=0 && xd;i--){
                if(b-(mid-i)<=a || mid-i+nums[i]>b-1)xd=false;
            }
            if(xd)l=mid;
            else r=mid-1;
        }
        cout << l <<'\n';
    }
}