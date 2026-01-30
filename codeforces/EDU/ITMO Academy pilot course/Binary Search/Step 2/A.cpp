#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,n,l,r=1e15;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> n;
    while(l<r){
        ll mid=(l+r)>>1;
        if(((long double)(mid/a))*((long double)(mid/b))/n>=1)r=mid;
        else l=mid+1;
    }
    cout << l;
}