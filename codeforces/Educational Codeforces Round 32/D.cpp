#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
ll n,k,res=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    if(k>=2)res+=n*(n-1)/2;
    if(k>=3)res+=2*n*(n-1)*(n-2)/6;
    if(k>=4)res+=9*n*(n-1)*(n-2)*(n-3)/24;
    cout << res;
}