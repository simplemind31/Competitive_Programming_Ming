#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 998244353
using namespace std;
int h,w;
int bigmod(int b,int e){
    int p=1;
    while(e){
        if(e&1)p=1ll*p*b%MOD;
        e>>=1;
        b=1ll*b*b%MOD;
    }
    return p;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> h >> w;
    cout << 1ll*4*bigmod(2,w+h-2)%MOD;
}