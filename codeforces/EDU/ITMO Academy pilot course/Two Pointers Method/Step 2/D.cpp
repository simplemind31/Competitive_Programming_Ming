#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> s;
    ll sum=0,j=0,nums[n],maxi=n+1,can=0;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        sum+=nums[i];
        while(sum>=s)sum-=nums[j++];
        can+=j;
    }
    cout << can;
}