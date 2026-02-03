#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t,l,r;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> l >> r;
        for(int i=1;i<=n;i++){
            if(i==r)cout << ((i-1)^(l-1)) << " \n"[i==n];
            else if(i==r+1)cout << (i^(l-1)) << " \n"[i==n];
            else cout << ((i-1)^i) << " \n"[i==n];
        }
    }
}