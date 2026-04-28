#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,maxi=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int l=1,r=n;
    while(l<r)cout << l++ << ' ' << r-- << ' ';
    if(l==r)cout << l;
}