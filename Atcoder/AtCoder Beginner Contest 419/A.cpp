#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    if(st=="red")cout << "SSS";
    else if(st=="blue")cout << "FFF";
    else if(st=="green")cout << "MMM";
    else cout << "Unknown";
}