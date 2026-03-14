#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char c;
int n,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int con=0;
        map<pair<int,int>,int> conta;
        for(int i=0;i<n;i++){
            cin >> c;
            con+=(c=='D');
            // con, n-con;
            int a=con,b=i+1-con;
            int mcd=gcd(a,b);
            a/=mcd;
            b/=mcd;
            cout << ++conta[{a,b}] << ' ';
        }
        cout << '\n';
    }
}