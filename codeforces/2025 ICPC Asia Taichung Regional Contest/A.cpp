#include <bits/stdc++.h>
using namespace std;
int g,c,l,ma,mi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> g >> c >> l;
    if((ma=max({g,c,l}))-(mi=min({g,c,l}))>=10)cout << "check again";
    else cout << "final " << g+c+l-ma-mi;
}