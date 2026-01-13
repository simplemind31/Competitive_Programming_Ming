#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int t=1,n,q,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> q;
        vector<int> psum(n);
        cin >> psum[0];
        for(int i=1;i<n;i++){
            cin >> a;
            psum[i]=psum[i-1]^a;
        }
        while(q--){
            cin >> a >> b;
            a--;b--;
            if(a==b)cout << "0\n";
            else cout << (psum[b-1]^((a==0)?0:psum[a-1])) << '\n';
        }
    }
}