#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll a,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a;
    for(ll i=sqrt(a);i>0;i--){
        if(!(a%i)){
            if(__gcd(i,a/i)==1){
                cout << i << ' ' << a/i;
                return 0;
            }
        }
    }
}