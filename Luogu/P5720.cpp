#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
int n,con=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n>1){
        con++;
        n>>=1;
    }
    cout << con;
}