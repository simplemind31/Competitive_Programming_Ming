#include <bits/stdc++.h>
using namespace std;
int A,B;
int extended_gcd(int a,int b,int& x,int& y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x1,y1,mcd=extended_gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(int)(a/b)*y1;
    return mcd;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> A >> B){
        int x,y,mcd=(extended_gcd(A,B,x,y));
        cout << x << ' ' << y << ' ' << mcd << '\n';
    }
}