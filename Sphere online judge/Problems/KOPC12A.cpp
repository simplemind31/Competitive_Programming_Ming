#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        pair<ll,ll> nums[n];
        ll iz[n],sum=0,mini=1e18,sum2=0;
        for(int i=0;i<n;i++)cin >> nums[i].first;
        for(int i=0;i<n;i++)cin >> nums[i].second;
        sort(nums,nums+n);
        iz[0]=0;
        sum=nums[0].second;
        for(int i=1;i<n;i++){
            iz[i]=iz[i-1]+sum*(nums[i].first-nums[i-1].first);
            sum+=nums[i].second;
        }
        mini=iz[n-1];
        sum=nums[n-1].second;
        for(int i=n-2;i>=0;i--){
            sum2=sum2+sum*(nums[i+1].first-nums[i].first);
            sum+=nums[i].second;
            mini=min(mini,sum2+iz[i]);
        }
        cout << mini << '\n';
    }
}