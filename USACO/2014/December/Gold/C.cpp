#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
ll t,a,b;
multiset<ll> lis;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("cowjog.in","r",stdin);
    freopen("cowjog.out","w",stdout);
    cin >> n >> t;
    lis.insert(2e18);
    while(n--){
        cin >> a >> b;
        a+=b*t;
        auto p=lis.lower_bound(a);
        if(p!=lis.begin())lis.erase(--p);
        lis.insert(a);
    }
    cout << lis.size()-1;
}