#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,con,c,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> a >> b;
    while(n--){
        cin >> c >> d;
        con+=c<=a && b<=d;
    }
    cout << con;
}