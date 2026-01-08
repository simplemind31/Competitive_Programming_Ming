#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
int t,n,x;
ll res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        res=0;
        cin >> n >> x;
        //ab+bc+ac<=n && a+b+c<=x
        for(ll i=1;i<=min(n,x);i++){
            for(ll j=1;i*j<=n && i+j<=x;j++){
                //c<=(n-i*j)/(i+j);
                //c<=x-i-j
                res+=min(x-i-j,(n-i*j)/(i+j));
            }
        }
        cout << res << '\n';
    }
}