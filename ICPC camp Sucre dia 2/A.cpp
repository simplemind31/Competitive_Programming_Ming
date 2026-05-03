#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n],iz[n],de[n];
    for(int i=0;i<n;i++)cin >> nums[i];
    iz[0]=nums[0];
    for(int i=1;i<n;i++)iz[i]=max(nums[i],iz[i-1]);
    de[n-1]=nums[n-1];
    for(int i=n-2;i>=0;i--)de[i]=max(de[i+1],nums[i]);
    for(int i=0;i<n;i++)cout << min(iz[i],de[i])+1 << ' ';
}