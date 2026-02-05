#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull a;
int main(){
    cin >> a;
    ull nue=a-3;
    ull res=(a-2)*nue*(nue+1)/2-nue*(nue+1)*(2*nue+1)/6;
    ull need=4;
    while(need%2==0 && res%2==0){
        need/=2;
        res/=2;
    }
    while(need%2==0 && a%2==0){
        a/=2;
        need/=2;
    }
    cout << a*res;
}