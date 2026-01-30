#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,mini,iz,nums[100000],maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout);
    cin >> n;
    for(ll i=0;i<n;i++)cin >> nums[i];
    sort(nums,nums+n);
    if(nums[n-1]-nums[1]==n-2 && nums[1]-nums[0]>2)mini=2;
    else if(nums[n-2]-nums[0]==n-2 && nums[n-1]-nums[n-2]>2)mini=2;
    else{
        ll j=0;
        for(ll i=0;i<n;i++){
            while(j<n-1 && nums[j+1]-nums[i]<=n-1)j++;
            mini=max(mini,j-i+1);
        }
        mini=n-mini;
    }
    maxi=max(nums[n-2]-nums[0],nums[n-1]-nums[1])-(n-2);
    cout << mini << '\n' << maxi;
}