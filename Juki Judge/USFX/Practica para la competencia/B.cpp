#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> x;
    for(int i=0;i<2;i++)x=abs(x)*(abs(x)+1)/2;
    cout << x;
}