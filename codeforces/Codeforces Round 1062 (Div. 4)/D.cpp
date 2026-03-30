#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a;
bitset<10001> criba;
vector<ll> primes;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    criba[0]=criba[1]=false;
    for(int i=2;i<=10000;i++){
        if(!criba[i])primes.push_back(i);
        for(int j=0;j<primes.size() && i*primes[j]<=10000;j++){
            criba[i*primes[j]]=true;
            if(i%primes[j]==0)break;
        }
    }
    cin >> t;
    while(t--){
        cin >> n;
        ll mini=1e18;
        for(int i=0;i<n;i++){
            cin >> a;
            for(auto u:primes){
                if(a%u!=0){
                    mini=min(mini,u);
                    break;
                }
            }
        }
        cout << mini << '\n';
    }
}