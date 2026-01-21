#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll k,ant,now,res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    cin >> ant;
    res=k+1;
    for(int i=1;i<n;i++){
        cin >> now;
        res+=min(k+1,now-ant);
        ant=now;
    }
    cout << res;
}