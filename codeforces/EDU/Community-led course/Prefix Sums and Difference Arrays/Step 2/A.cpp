#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,a,q,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll psum[n+1];
    psum[0]=0;
    for(int i=1;i<=n;i++){
        cin >> a;
        psum[i]=psum[i-1]+a;
    }
    cin >> q;
    while(q--){
        cin >> a >> b;
        cout << psum[b]-psum[a-1] << '\n';
    }
}