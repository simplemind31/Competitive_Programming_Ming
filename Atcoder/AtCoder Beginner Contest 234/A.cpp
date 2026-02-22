#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int f(int x){return x*x+2*x+3;}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    cout << f(f(f(t)+t)+f(f(t)));
}