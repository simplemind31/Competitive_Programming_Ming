#include <bits/stdc++.h>
using namespace std;
int n,m,a,l,r,mid;
long long suma,need;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> a;
    int b[n],p[m];
    for(int i=0;i<n;i++)cin >> b[i];
    for(int i=0;i<m;i++)cin >> p[i];
    sort(b,b+n);
    sort(p,p+m);
    r=min(n,m);
    while(l<r){
        mid=(l+r+1)>>1;need=0;
        for(int i=1;i<=mid;i++)need+=max(0,p[mid-i]-b[n-i]);
        if(need>a)r=mid-1;
        else l=mid;
    }
    cout << l << ' ';
    // minimum to achieve l
    // comprar los primerso l mas baratos, y usando los que tienen mas dinero.
    for(int i=0;i<l;i++)suma+=p[i];
    cout << max(suma-a,0ll);
}