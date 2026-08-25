#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2000000;
int t;
ll n;
bitset<MAXN+1> criba;
vector<ll> primes;
bool isprime(ll x){
    for(int j=0;primes[j]*primes[j]<=x;j++)if(x%primes[j]==0)return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    criba[0]=criba[1]=1;
    for(int i=2;i<=MAXN;i++){
        if(!criba[i])primes.push_back(i);
        for(int j=0;j<primes.size() && i*primes[j]<=MAXN;j++){
            criba[i*primes[j]]=1;
            if(i%primes[j]==0)break;
        }
    }
    cin >> t;
    while(t--){
        cin >> n;
        while(!isprime(++n));
        cout << n << '\n';
    }
}