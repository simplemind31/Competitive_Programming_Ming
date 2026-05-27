#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("test10.in","w",stdout);
    int n=100000;
    mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
    int nums[n];
    for(int i=0;i<n;i++)nums[i]=i+1;
    shuffle(nums,nums+n,rng);
    cout << n << '\n';
    for(int i=0;i<n-2;i++)cout << nums[i] << ' ';
}