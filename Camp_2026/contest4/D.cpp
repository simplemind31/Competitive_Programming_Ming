#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
string a,b,c,d;
bool A,B,C,D;
int con=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> c >> d;
    A=((a.back()-'0')&1);
    B=((b.back()-'0')&1);
    C=((c.back()-'0')&1);
    D=((d.back()-'0')&1);
    A=!A;
    B=!B;
    C=!C;
    D=!D;
    if((B||C||D)==A)con++;
    if((A||C||D)==B)con++;
    if((B||A||D)==C)con++;
    if((B||C||A)==D)con++;
    cout << con;
}