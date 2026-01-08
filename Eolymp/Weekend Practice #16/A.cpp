#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int t=1,n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<ll> res(n);
        for(int i=0;i<n;i++){
            cin >> res[i];
        }
        for(int j=0;j<k;j++){
            ll suma=0;
            for(int i=0;i<n;i++){
                res[i]-=suma;
                suma+=res[i];
            }
        }
        for(int i=0;i<n;i++){
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
}