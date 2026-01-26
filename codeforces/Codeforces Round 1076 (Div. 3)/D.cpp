#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
ll n,t=1,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ll maxi=0;
        map<ll,ll> con;
        for(int i=0;i<n;i++){
            cin >> a;
            con[a]++;
        }
        ll b[n+1],psum[n+1],now=0;
        b[0]=psum[0]=0;
        for(int i=1;i<=n;i++){
            cin >> b[i];
            psum[i]=b[i]+psum[i-1];
        }
        for(auto u:con){
            //hay n-now disponible
            int pos=upper_bound(psum,psum+n+1,n-now)-psum-1;
            maxi=max(maxi,1LL*pos*(u.first));
            now+=u.second;
        }
        cout << maxi << '\n';
    }
}