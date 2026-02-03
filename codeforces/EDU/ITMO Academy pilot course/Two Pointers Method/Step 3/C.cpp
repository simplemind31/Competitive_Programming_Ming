#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> s;
    ll j=0,nums[n],can=0;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        while(nums[i]-nums[j]>s)j++;
        can+=j;
    }
    cout << can;
}