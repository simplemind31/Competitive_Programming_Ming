#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
unsigned int a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a;
        cout << (((1<<32)-1)^a) << '\n';
    }
}