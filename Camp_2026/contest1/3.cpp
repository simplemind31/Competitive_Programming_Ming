#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    vector<pair<ll,ll>> nums(n);
    for(ll i=0;i<n;i++){
        cin >> nums[i].first;
        nums[i].second=i+1;
    }
    sort(nums.begin(),nums.end());
    int i=0,j=n-1;
    while(i<j){
        ll suma=nums[i].first+nums[j].first;
        if(suma==k){
            cout << min(nums[i].second,nums[j].second) << ' ' << max(nums[i].second,nums[j].second);
            return 0;
        }
        if(suma<k)i++;
        else j--;
    }
    cout << "IMPOSSIBLE";
}
