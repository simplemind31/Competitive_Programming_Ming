#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> c >> d;
    cout << (c*60+d-(a*60+b))/60 << ' ' << (c*60+d-(a*60+b))%60;
}