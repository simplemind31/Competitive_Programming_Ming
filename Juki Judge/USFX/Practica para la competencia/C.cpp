#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> x >> y >> a;
    switch (a){
    case 1:
    x+=3;
    y-=2;
    break;
    case 2:
    x*=2;
    break;
    case 3:
    x*=-1;
    y*=-1;
    break;
    case 4:
    swap(x,y);
    break;
    case 5:
    x-=5;
    y+=5;
    break;
    }
    cout << x << ' ' << y;
}