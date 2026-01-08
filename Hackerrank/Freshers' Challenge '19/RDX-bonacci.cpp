#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll n,rn;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> rn >> n;
    for(int k=100;k>=0;k--){
        vector<ll> fib(n+k+1),psum(n+k+1);
        for(int i=1;i<=k;i++){
            fib[i]=1;
            psum[i]=psum[i-1]+fib[i];
        }
        for(int i=k+1;i<=n;i++){
            fib[i]=psum[i-1]-psum[i-k-1];
            fib[i]+=MOD;
            fib[i]%=MOD;
            fib[i]%=MOD;
            psum[i]=psum[i-1]+fib[i];
            psum[i]%=MOD;
        }
        if(fib[n]==rn){
            cout << k;
            return 0;
        }
    }
}