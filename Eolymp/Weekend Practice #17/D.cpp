#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long,long long> pll;
ll n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<ll> nums(n);
    for(ll i=0;i<n;i++){
        cin >> nums[i];
    }
    if(n==1){
        if(nums[0]==1)cout << 1;
        else cout << nums[0]*(nums[0]-1)-(nums[0]-1);
        return 0;
    }
    cout << nums[0]*(nums[0]-1);
}