#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bitset<100> ex;
int n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a;
        ex[--a]=true;
    }
    cin >> a;
    cout << (ex[--a]?"Yes":"No");
}