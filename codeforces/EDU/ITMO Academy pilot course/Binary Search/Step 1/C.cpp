#include <bits/stdc++.h>
using namespace std;
int n,q,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    int  nums[n];
    for(int i=0;i<n;i++)cin >> nums[i];
    sort(nums,nums+n);
    while(q--){
        cin >> a;
        cout << lower_bound(nums,nums+n,a)-nums+1 << '\n';
    }
}