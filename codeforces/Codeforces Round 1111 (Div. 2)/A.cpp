#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int t=1,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int res=0,a;
        for(int i=0;i<n;i++){
            cin >> a;
            res+=a;
        }
        if(res%4==0)cout << "YES\n";
        else cout << "NO\n";
    }
}