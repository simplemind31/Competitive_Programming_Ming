#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
ld a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(10);
    cin >> a >> b >> c;
    if(a==0){
        if(b==0){
            if(c==0)cout << -1;
            else cout << 0;
        }
        else cout << "1\n" << -c/b;
    }else{
        if(b*b-4*a*c<0)cout << 0;
        else if(b*b-4*a*c==0)cout << "1\n" << -b/(2*a);
        else{
            ld x,y;
            cout << "2\n";
            x=(-b+sqrt(b*b-4*a*c))/(2*a);
            y=(-b-sqrt(b*b-4*a*c))/(2*a);
            if(x>y)swap(x,y);
            cout << x << '\n' << y;
        }
    }
}