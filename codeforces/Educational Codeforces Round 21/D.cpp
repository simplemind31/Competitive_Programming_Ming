#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,sum;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll nums[n];
    map<ll,bool> con;
    for(ll i=0;i<n;i++){
        cin >> nums[i];
        sum+=nums[i];
    }
    if(sum&1){
        cout << "NO";
        return 0;
    }
    ll psum=0;
    con[0]=true;
    for(int i=0;i<n;i++){
        if(con[sum/2-nums[i]]){
            cout << "YES";
            return 0;
        }
        psum+=nums[i];
        con[psum]=true;
    }
    psum=0;
    con.clear();
    con[0]=true;
    for(int i=n-1;i>=0;i--){
        if(con[sum/2-nums[i]]){
            cout << "YES";
            return 0;
        }
        psum+=nums[i];
        con[psum]=true;
    }
    cout << "NO\n";
}