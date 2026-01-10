#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
ll t,n,w;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> w;
        ll mini=1e18;
        vector<ll> nums(n+1);
        vector<ll> suma(2*w);
        for(int i=1;i<=n;i++){
            cin >> nums[i];
            suma[i%(2*w)]+=nums[i];
        }
        ll now=0;
        for(int i=0;i<w;i++){
            now+=suma[i];
        }
        mini=min(mini,now);
        for(int i=w;i<3*w;i++){
            now-=suma[((i-w)%(2*w)+2*w)%(2*w)];
            now+=suma[i%(2*w)];
            mini=min(mini,now);
        }
        cout << mini << '\n';
    }
}