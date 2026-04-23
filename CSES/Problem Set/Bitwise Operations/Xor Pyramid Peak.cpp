#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int MAXN=200000;
int n,fact[MAXN+1],a,res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=MAXN;i++)fact[i]=fact[i-1]+__builtin_ctz(i);
    for(int i=0;i<n;i++){
        cin >> a;
        if(fact[n-1]-(fact[i]+fact[n-1-i])==0)res^=a;
    }
    cout << res;
}