#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,c,k,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> c >> k;
        ll nums[n];
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        sort(nums,nums+n);
        for(int i=0;i<n && nums[i]<=c;i++){
            ll mini=min(c-nums[i],k);
            nums[i]+=mini;
            k-=mini;
            c+=nums[i];
        }
        cout << c << '\n';
    }
}