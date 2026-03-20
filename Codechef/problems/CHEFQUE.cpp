#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
bitset<(1ll<<31)+1> exis;
int q;
unsigned int s,a,b;
ll sum;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> q >> s >> a >> b;
    while(q--){
        if(s&1){
            if(!exis[s>>1])sum+=s>>1;
            exis[s>>1]=1;
        }else{
            if(exis[s>>1])sum-=s>>1;
            exis[s>>1]=0;
        }
        s=a*s+b;
    }
    cout << sum;
}