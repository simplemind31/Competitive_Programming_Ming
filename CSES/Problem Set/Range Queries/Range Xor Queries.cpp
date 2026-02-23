#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,q,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    int pxor[n+1];
    pxor[0]=0;
    for(int i=1;i<=n;i++){
        cin >> pxor[i];
        pxor[i]^=pxor[i-1];
    }
    while(q--){
        cin >> a >> b;
        cout << (pxor[b]^pxor[a-1]) << '\n';
    }
}