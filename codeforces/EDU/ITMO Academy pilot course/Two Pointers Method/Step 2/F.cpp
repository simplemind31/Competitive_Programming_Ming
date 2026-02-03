#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> s;
    ll j=0,nums[n],can=0;
    multiset<ll> cont;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        while(!cont.empty() && (nums[i]-*cont.begin()>s || *(--cont.end())-nums[i]>s))cont.erase(cont.find(nums[j++]));
        cont.insert(nums[i]);
        can+=i-j+1;
    }
    cout << can;
}