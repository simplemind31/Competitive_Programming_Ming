#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
bool xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=63;i>=0;i--){
        if(n&(1ll<<i)){
            xd=true;
            cout << 2;
        }else if(xd)cout << 0;
    }
}