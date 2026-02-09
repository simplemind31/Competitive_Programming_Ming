#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b;
    if(b!=2)cout << 30+((b<=7)==(b&1));
    else if(a%400==0 || a%100 && a%4==0)cout << 29;
    else cout << 28;
}