#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
int n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    int can=n/k;
    cout << fixed << setprecision(1) << (double)(1+can)*can/2*k/can << ' ' << (double)(n*(n+1)/2-(1+can)*can/2*k)/(n-can);
}