#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 998244353
using namespace std;
int q,t,a,b;
pair<int,int> f={1,0};
queue<pair<int,int>> functions;
int bigmod(int b,int e){
    int p=1;
    while(e){
        if(e&1)p=1ll*p*b%MOD;
        e>>=1;
        b=1ll*b*b%MOD;
    }
    return p;
}
int inversemod(int b){
    return bigmod(b,MOD-2);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> q;
    while(q--){
        cin >> t;
        if(t==0){
            cin >> a >> b;
            f={1ll*f.first*a%MOD,(1ll*f.second*a+b)%MOD};
            functions.push({a,b});
        }else if(t==2){
            cin >> a;
            cout << (1ll*f.first*a+f.second)%MOD << '\n';
        }else{
            int p=1ll*f.first*inversemod(functions.front().first)%MOD;
            int q=(f.second-1ll*functions.front().second*p%MOD+MOD)%MOD;
            f={p,q};
            functions.pop();
        }
    }
}