#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>n;
    if(400%n)cout << -1;
    else cout << 400/n;
}