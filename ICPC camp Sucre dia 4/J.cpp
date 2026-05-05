#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;
int t;
ll n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    // 1 2 3 4 5
    // 6 7 8 9 10
    // 11 12 13 14 15
    while(t--){
        cin >> n >> m;
        cout << m*(m+1)/2+m*n*(n+1)/2-m << '\n';
    }
}
