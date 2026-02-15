#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
double r;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    r=sqrtl(5);
    cout << fixed << setprecision(2) << (powl((1+r)/2,n)-powl((1-r)/2,n))/r;
}