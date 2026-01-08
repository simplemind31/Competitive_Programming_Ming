#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
ll res[40];
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    res[0]=1;
    for(ll i=1;i<40;i++){
        res[i]=res[i-1]*(i+1)/__gcd(res[i-1],i+1);
    }
    cin >> t;
    while(t--){
        cin >> n;
        cout << res[n-1] << '\n';
    }
}