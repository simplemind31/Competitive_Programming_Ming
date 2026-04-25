#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
#define MOD 998244353
using namespace std;
typedef long long ll;
int n,a,b;
bitset<5000001> nueposi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("feast.in","r",stdin);
    freopen("feast.out","w",stdout);
    cin >> n >> a >> b;
    nueposi[0]=1;
    for(int i=0;i<=n;i++){
        if(nueposi[i]){
            if(i+a<=n)nueposi[i+a]=1;
            if(i+b<=n)nueposi[i+b]=1;
            nueposi[i/2]=1;
        }
    }
    for(int i=0;i<=n;i++){
        if(nueposi[i]){
            if(i+a<=n)nueposi[i+a]=1;
            if(i+b<=n)nueposi[i+b]=1;
        }
    }
    for(int i=n;i>=0;i--){
        if(nueposi[i]){
            cout << i;
            break;
        }
    }
}