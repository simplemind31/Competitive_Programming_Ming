#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    n=min(n,k-1);
    a=k-n;
    if(a>=n)cout << 0;
    else cout << (n-a+1)/2;
}