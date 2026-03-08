#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,l,sum=1e-18,maxi=-1e18,resl,resr=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll nums[n+1];
    nums[0]=0;
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        nums[i]+=nums[i-1];
        if(nums[i]-nums[l]>maxi){
            maxi=nums[i]-nums[l];
            resl=l;
            resr=i;
        }
        if(nums[i]<nums[l])l=i;
    }
    cout << resl+1 << ' ' << resr << ' ' << maxi;
}