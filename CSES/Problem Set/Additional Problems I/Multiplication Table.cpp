#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,l=1,r;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    k=(n*n+1)/2;
    r=n*n;
    while(l<r){
        ll mid=(l+r)>>1,suma=0;
        // suma de todo menor igual que mid;
        for(int i=1;i<=n;i++)suma+=min(mid/i,n);
        if(suma>=k)r=mid;
        else l=mid+1;
    }
    cout << l;
}