#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll a,b,res;
ll serie[2000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(ll i=1;i<=2000000;i++){
        if(i&1){
            serie[i]=i;
        }else{
            serie[i]=i*i/4;
        }
    }
    cin >> a >> b;
    for(ll i=1;i<=2000000-3;i++){
        if(a==serie[i] && b==serie[i+3]){
            res=serie[i+1]+serie[i+2];
            cout << res;
            return 0;
        }
    }
}
