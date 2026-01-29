#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long double l,r,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c;
    r=sqrtl(c);
    while(abs(l-r)>1e-12){
        long double mid=(l+r)/2;
        if(mid*mid+sqrtl(mid)<=c)l=mid;
        else r=mid;
    }
    cout << fixed << setprecision(12) << l;
}