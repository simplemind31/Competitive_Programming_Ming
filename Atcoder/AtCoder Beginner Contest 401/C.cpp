#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll fib[1000001],suma;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=0;i<k;i++)fib[i]=1;
    suma=k;
    for(int i=k;i<=n;i++)suma=(suma+(fib[i]=suma)-fib[i-k]+(ll)1e9)%((ll)1e9);
    cout << fib[n];
}