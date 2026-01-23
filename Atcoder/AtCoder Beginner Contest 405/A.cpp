#include <bits/stdc++.h>
using namespace std;
int r,x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> r >> x;
    if((x==1 && 1600<=r && r<=2999)||(x==2 && 1200<=r && r<=2399))cout << "Yes";
    else cout << "No";
}