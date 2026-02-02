#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n;
bool cmp(const string& x, const string& y){return x+y<y+x;}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    string cad[n];
    for(int i=0;i<n;i++)cin >> cad[i];
    sort(cad,cad+n,cmp);
    for(int i=0;i<n;i++)cout << cad[i];
}