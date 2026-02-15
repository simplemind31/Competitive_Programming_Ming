#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    n/=364;
    x=min(n,100);
    while((n-x)%3 || (n-x)/3==0)x--;
    cout << x << '\n' << (n-x)/3;
}