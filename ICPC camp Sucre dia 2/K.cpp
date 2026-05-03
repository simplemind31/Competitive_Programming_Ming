#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> a;
    cout << ((m-1)/a+1)*((n-1)/a+1);
}