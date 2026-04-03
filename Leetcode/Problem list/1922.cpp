#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
class Solution {
public:
    ll bigmod(ll b,ll e){
        ll p=1;
        while(e){
            if(e&1)p=p*b%MOD;
            b=b*b%MOD;
            e>>=1;
        }
        return p;
    }
    int countGoodNumbers(ll n){return bigmod(5,(n+1)>>1)*bigmod(4,n>>1)%MOD;}
};