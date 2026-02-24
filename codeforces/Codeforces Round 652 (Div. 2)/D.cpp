#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;
const int MAXN=2000000;
int n,t;
ll res[MAXN];
// 0=no use root,1 use
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    res[0]=res[1]=0;
    for(int i=2;i<MAXN;i++){
        res[i]=(res[i-1]+2*res[i-2]+(i%3==2)*4)%MOD;
    }
    cin >> t;
    while(t--){
        cin >> n;
        cout << res[--n] << '\n';
    }
}