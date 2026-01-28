#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    int nums[n];
    for(int i=0;i<n;i++)cin >> nums[i];
    for(int i=1;i<n;i++)nums[i]=max(nums[i],nums[i-1]-k);
    for(int i=n-2;i>=0;i--)nums[i]=max(nums[i],nums[i+1]-k);
    for(int i=0;i<n;i++)cout << nums[i] << ' ';
}