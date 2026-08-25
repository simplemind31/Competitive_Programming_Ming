#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,res,now;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=63;i>=0;i--){
        if(!(n&(1ll<<i)))continue;
        // este uso 0 y el resto cualquiera
        res+=now*(1ll<<i)+i*(1ll<<(i-1));
        now++;
    }
    cout << res+now;
}