#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,l,r;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> l >> r;
        for(int i=0;i<64;i++){
            if(!(l&(1ll<<i))){
                if((l|(1ll<<i))<=r){
                    l|=(1ll<<i);
                }else{
                    break;
                }
            }
        }
        cout << l << '\n';
    }
}