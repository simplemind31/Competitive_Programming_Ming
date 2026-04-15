#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
#define MOD 1000000007
int t,n,k,a;
vector<pair<int,int>> nums;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        int suma=0;
        for(int i=0;i<n;i++){
            cin >> a;
            suma=(suma+a)%2;
        }
        if(n*k%2==0 || suma)cout << "YES\n";
        else cout << "NO\n";
    }
}