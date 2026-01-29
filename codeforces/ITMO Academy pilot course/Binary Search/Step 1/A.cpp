#include <bits/stdc++.h>
using namespace std;
int n,q,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    int  nums[n];
    for(int i=0;i<n;i++)cin >> nums[i];
    while(q--){
        cin >> a;
        cout << (binary_search(nums,nums+n,a)?"YES\n":"NO\n");
    }
}