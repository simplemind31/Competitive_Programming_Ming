#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
ll x,k,n,suma;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k >> x;
    vll nums(n);
    for(int i=0;i<n;i++)cin >> nums[i];
    sort(ALL(nums));
    int pos=k-1;
    for(;pos>=0;pos--){
        suma+=nums[pos];
        if(suma>=x)break;
    }
    if(pos==-1)cout << -1;
    else cout << n-pos;
}
