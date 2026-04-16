#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    bitset<1000001> criba;
    criba[0]=criba[1]=true;
    vector<int> primes;
    for(int i=2;i<=1000000;i++){
        if(!criba[i])primes.push_back(i);
        for(int j=0;j<primes.size() && primes[j]*i<=1000000;j++){
            criba[i*primes[j]]=true;
            if(i%primes[j]==0)break;
        }
    }
    //for(int i=0;i<100;i++)cout <<primes[i] << '\n';
    cin >> t;
    while(t--){
        cin >> n;
        int now=0;
        for(int i=1;i<n;i+=2){
            cout << 1ll*primes[now]*primes[now] << ' ' << 1ll*primes[now]*primes[now]*primes[now+1] << ' ';
            now++;
        }
        if(n&1)cout << 1ll*primes[now]*primes[now];
        cout << '\n';
    }
}