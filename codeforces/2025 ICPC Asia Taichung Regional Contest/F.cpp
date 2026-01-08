#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll suma;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> nums(n),prefmcd(n),sufmcd(n),res(n);
    for(int i=0;i<n;i++)cin >> nums[i];
    prefmcd[0]=nums[0];
    sufmcd[n-1]=nums[n-1];
    for(int i=1;i<n;i++)prefmcd[i]=__gcd(prefmcd[i-1],nums[i]);
    for(int i=n-2;i>=0;i--)sufmcd[i]=__gcd(sufmcd[i+1],nums[i]);
    for(int i=1;i<n-1;i++)suma+=min(prefmcd[i],sufmcd[i]);
    suma+=sufmcd[0];
    cout << suma;
}