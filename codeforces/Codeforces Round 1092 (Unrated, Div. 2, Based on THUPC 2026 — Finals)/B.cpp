#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res,n,h,u,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        res=0;
        cin >> t >> h >>u;
        ll mini=min(t,u);
        res+=mini*4;
        t-=mini;
        u-=mini;
        if(u){
            res+=(u+h)*3;
        }else{
            // 1 h y 2 t=>7
            // 1 h y 1t =>5
            // 1t=3
            // 2t=5
            // 3t=7
            // 4t=9
            mini=min(h,t/2);
            res+=mini*7;
            h-=mini;
            t-=2*mini;
            mini=min(t,h);
            res+=5*mini;
            t-=mini;
            h-=mini;
            res+=h*3;
            if(t)res+=t*2+1;
        }
        cout << res << '\n';
    }
}