#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> d >> a >> b;
    if(a<c||(a==c && b<d))cout << "Yes";
    else cout << "No";
}