#include <bits/stdc++.h>
using namespace std;
int a,n,res;
int main(){
    cin >> a >> n;
    a--;
    res+=(n/7)*5*250;
    n%=7;
    res+=n*250;
    if(a<=5 && 5<=a+n-1)res-=250;
    if(a<=6 && 6<=a+n-1)res-=250;
    cout << res;
}