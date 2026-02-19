#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n,last,now,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> last;
        maxi=0;
        while(--n){
            cin >> now;
            if(now>=last){
                last=now;
                continue;
            }
            maxi=max(maxi,32-__builtin_clz(last-now));
        }
        cout << maxi << '\n';
    }
}