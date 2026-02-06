#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x;
bool a(int y){return !(y&1);}
bool b(int y){return y>4 && y<=12;}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> x;
    cout << (a(x)&b(x)) << ' ' << (a(x)|b(x)) << ' ' << (a(x)^b(x)) << ' ' << (!(a(x)|b(x)));
}