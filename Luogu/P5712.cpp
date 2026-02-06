#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> x;
    cout << "Today, I ate " << x << " apple" << ((x<2)?".":"s.");
}