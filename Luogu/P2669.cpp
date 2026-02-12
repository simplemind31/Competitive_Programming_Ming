#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
int k;
double num=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> k;
    int x=(-1+sqrt(1+4*k))/2;
    while(x*(x+1)/2<=k)x++;
    while(x*(x+1)/2>k)x--;
    cout << x*(x+1)*(2*x+1)/6+(k-x*(x+1)/2)*(x+1);
}