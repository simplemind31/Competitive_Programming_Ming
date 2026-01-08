#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll n,sum=1,a;
bool xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> a;
    xd|=(a&1);
    for(int i=1;i<n;i++){
        cin >> a;
        xd|=(a&1);
        sum=(sum*2)%MOD;
    }
    if(!xd)sum=(sum*2)%MOD;
    cout << (sum=(sum+MOD-1)%MOD);
}