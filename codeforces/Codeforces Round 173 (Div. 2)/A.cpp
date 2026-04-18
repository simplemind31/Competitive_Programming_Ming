#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,x;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> st;
        if(st[1]=='+')x++;
        else x--;
    }
    cout << x;
}