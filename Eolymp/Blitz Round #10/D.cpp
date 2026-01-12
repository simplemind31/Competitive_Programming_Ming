#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
ll n,q,a,b,c,d,pow2[64],psum[64],con=1,depth=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    pow2[0]=psum[0]=1;
    for(int i=1;con<n;i++){
        psum[i]=con+=pow2[i]=min(n-con,pow2[i-1]<<1);
        depth++;
    }
    while(q--){
        cin >> a >> b >> c >> d;
        if(a>d || a>depth || c>depth){
            cout << "0\n";
            continue;
        }
        c=max(c,a);
        b=min(b,d=min(d,depth));
        ll res=0;
        for(ll i=a;i<=b;i++)res+=psum[d]-((max(i-1,c-1)<0)?0:psum[max(i-1,c-1)]);
        cout << res << '\n';
    }
}