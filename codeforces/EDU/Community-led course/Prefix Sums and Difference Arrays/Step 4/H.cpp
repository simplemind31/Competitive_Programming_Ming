#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,a,b,q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll psum[n+2];
    memset(psum,0,sizeof(psum));
    for(int i=1;i<=n;i++){
        cin >> a;
        psum[i]+=a;
        psum[i+1]-=a;
    }
    cin >> q;
    while(q--){
        cin >> a >> b;
        psum[n-a+1]+=b;
    }
    for(int i=1;i<=n;i++){
        cout << (psum[i]+=psum[i-1]) << ' ';
    }
}