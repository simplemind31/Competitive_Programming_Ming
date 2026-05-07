#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll res;
ll sq(ll a){return a*a;}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n];
    for(int i=0;i<n;i++)cin >> nums[i];
    sort(nums,nums+n);
    for(int i=0;i<n/2;i++)res+=sq(nums[i]+nums[n-i-1]);
    cout << res;
}