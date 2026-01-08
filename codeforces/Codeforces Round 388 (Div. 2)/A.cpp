#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    cout << n/2 << '\n';
    if(n%2){
        cout << 3 << ' ';
        n-=3;
    }
    while(n){
        n-=2;
        cout << 2 << ' ';
    }
}