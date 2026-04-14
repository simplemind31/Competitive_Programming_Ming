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
    int j=n-1;
    for(int i=0;i<n;i++){
        while(nums[i].first+nums[j].first>k && j-1>i)j--;
        if(nums[i].first+nums[j].first==k){
            cout << min(nums[i].second,nums[j].second) << ' ' << max(nums[i].second,nums[j].second);
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}
