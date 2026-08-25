#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __float128 ld;
int n,x;
ld con[100],res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        for(int k=0;k<100;k++)res+=con[k]*min(k,x)/x;
        for(int j=0;j<x;j++)con[j]+=(ld)1/x;
    }
    cout << fixed << setprecision(6) << (long double)res;
}