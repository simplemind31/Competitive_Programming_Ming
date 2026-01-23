#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;
ll x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> q;
    while(q--){
        cin >> x;
        ll sq=(-1+sqrt(1+4*x))/2;
        if(sq*(sq+1)/2>=x)sq--;
        x-=sq*(sq+1)/2;
        cout << x << '\n';
    }
}