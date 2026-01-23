#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,x,y,z,w;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    cin >> a >> b >> c >> d >> x >> y >> z >> w;
    cout << pow(max(max(c,z)-min(a,x),max(d,w)-min(b,y)),2);
}