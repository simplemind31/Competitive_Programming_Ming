#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    if(n&1)n++;
    cout << n*(n*n-1)/6;
}