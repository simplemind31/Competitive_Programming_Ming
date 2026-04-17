#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,a,b,c,n;
ll bigmod(ll b,ll e){
    ll p=1;
    while(e){
        if(e&1)p*=b;
        b*=b;
        e>>=1;
    }
    return p;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    bitset<100001> criba;
    criba[0]=criba[1]=true;
    vector<int> primes;
    for(int i=2;i<=100000;i++){
        if(!criba[i])primes.push_back(i);
        for(int j=0;j<primes.size() && i*primes[j]<=100000;j++){
            criba[i*primes[j]]=true;
            if(i%primes[j]==0)break;
        }
    }
    while(t--){
        cin >> a >> b >> c;
        a=a*b*c;
        if(a==1){
            cout << "-1\n";
            continue;
        }
        vector<pair<ll,ll>> fact;
        for(ll i=0;i<primes.size() && primes[i]*primes[i]<=a;i++){
            if(a%primes[i]==0){
                fact.push_back({primes[i],0});
                while(a%primes[i]==0){
                    fact.back().second++;
                    a/=primes[i];
                }
            }
        }
        if(a>1)fact.push_back({a,1});
        int mcd=0;
        n=fact.size();
        for(int i=0;i<n;i++){
            mcd=gcd(mcd,fact[i].second);
        }
        if(mcd==1){
            cout << "-1\n";
            continue;
        }
        // encontrar minimo divisor de mcd
        int divi=mcd;
        for(int i=2;i*i<=mcd;i++){
            if(mcd%i==0){
                divi=i;
                break;
            }
        }
        int res=1;
        for(int i=0;i<n;i++)res*=bigmod(fact[i].first,fact[i].second/divi);
        cout << res << " a la " << divi << '\n';
    }
}