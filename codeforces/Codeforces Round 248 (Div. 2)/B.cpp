#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,q,t,x,y;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll a[n+1],b[n+1];
    a[0]=b[0]=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        b[i]=a[i];
    }
    sort(b,b+n+1);
    for(int i=1;i<=n;i++){
        b[i]+=b[i-1];
        a[i]+=a[i-1];
    }
    cin >> q;
    while(q--){
        cin >> t >> x >> y;
        if(t==1)cout << a[y]-a[x-1] << '\n';
        else cout << b[y]-b[x-1] << '\n';
    }
}