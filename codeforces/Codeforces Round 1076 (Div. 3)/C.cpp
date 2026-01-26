#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<long long> vll;
typedef pair<ll,ll> pii;
typedef pair<long long,long long> pll;
ll n,t=1,q,x,y;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> q;
        ll a[n],b[n],psum[n+1];
        for(int i=0;i<n;i++)cin >> a[i];
        for(int i=0;i<n;i++)cin >> b[i];
        a[n-1]=max(a[n-1],b[n-1]);
        for(int i=n-2;i>=0;i--)a[i]=max({a[i],a[i+1],b[i]});
        psum[0]=0;
        for(int i=1;i<=n;i++)psum[i]=psum[i-1]+a[i-1];
        while(q--){
            cin >> x >> y;
            cout << psum[y]-psum[x-1] << ' ';
        }
        cout << '\n';
    }
}