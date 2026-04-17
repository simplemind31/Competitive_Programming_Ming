#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,a;
ll sum,res;
map<ll,ll> con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    con[0]=true;
    for(int i=0;i<n;i++){
        cin >> a;
        sum+=a;
        res+=con[sum-m];
        con[sum]++;
    }
    cout << res;
}