#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll sum,val;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n];
    for(int i=0;i<n;i++)cin >> nums[i];
    sort(nums,nums+n);
    reverse(nums,nums+n);
    for(int i=0;i<n;i++){
        if(1LL*(i+1)*nums[i]>=sum){
            sum=1LL*(i+1)*nums[i];
            val=nums[i];
        }
    }
    cout << sum << ' ' << val;
}