#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k,n;
ll l,r=1e12;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> k >> n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    sort(nums,nums+n);
    reverse(nums,nums+n);
    while(l<r){
        ll mid=(l+r+1)>>1;
        ll now=0;
        for(int i=0;i<n;i++)now+=min((ll)nums[i],mid);
        if(now>=mid*k)l=mid;
        else r=mid-1;
    }
    cout << l;
}