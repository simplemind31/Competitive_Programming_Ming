#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n,sum=2,fib[1000];
vector<pair<ll,ll>> res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fib[0]=1;
    fib[1]=2;
    res.push_back({1,0});
    res.push_back({2,2});
    for(int i=2;i<1000;i++){
        fib[i]=fib[i-1]+fib[i-2];
        if(fib[i]>4e16)break;
        if(fib[i]%2==0){
            sum+=fib[i];
            res.push_back({fib[i],sum});
        }
    }
    cin >> t;
    while(t--){
        cin >> n;
        cout << (--lower_bound(res.begin(),res.end(),make_pair(n+1,0ll)))->second << '\n';
    }
}