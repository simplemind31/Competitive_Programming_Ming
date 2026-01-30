#include <bits/stdc++.h>
using namespace std;
int n,q,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int  nums[n];
    for(int i=0;i<n;i++)cin >> nums[i];
    sort(nums,nums+n);
    cin >> q;
    while(q--){
        cin >> a >> b;
        cout << upper_bound(nums,nums+n,b)-nums-1-(lower_bound(nums,nums+n,a)-nums)+1 << ' ';
    }
}