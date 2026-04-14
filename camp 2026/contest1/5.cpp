#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ll x=(-1+sqrt(1+8*n))/2;
        if(x*(x+1)/2==n)cout << "Go On Boy " << x << '\n';
        else cout << "Better Luck Next Time\n";
    }
}
