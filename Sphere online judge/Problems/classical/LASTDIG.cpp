#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int bigmod(int b,int e){
    int p=1;
    while(e){
        if(e&1)p=p*b%10;
        b=b*b%10;
        e>>=1;
    }
    return p;
}
int n,m,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << bigmod(n,m) << '\n';
    }
}