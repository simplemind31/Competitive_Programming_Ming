#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,l=2,r=2e9,suma;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    int a[n],b[n];
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++)cin >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    while(l<r){
        ll mid=(l+r)>>1;
        for(int i=suma=0;i<n;i++)suma+=upper_bound(b,b+n,mid-a[i])-b;
        if(suma>=k)r=mid;
        else l=mid+1;
    }
    cout << l;
}