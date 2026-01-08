#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,a;
ll res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        res=0;
        cin >> n >> m;
        vector<ll> con(n+1),psum(n+1);
        for(int i=0;i<m;i++){
            cin >> a;
            con[a]++;
        }
        // minimo 1 y minimo n-1, minimo 2 y minimo n-2
        psum[n]=con[n];
        for(int i=n-1;i>=0;i--){
            psum[i]=psum[i+1]+con[i];
        }
        for(int i=1;2*i<n;i++){
            res+=psum[n-i]*psum[i]-psum[n-i];
        }
        res*=2;
        if(n%2==0){
            res+=psum[n/2]*psum[n/2]-psum[n/2];
        }
        cout << res << '\n';
    }
}