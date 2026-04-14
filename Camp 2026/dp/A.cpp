#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll> cost;
ll mini=1e18;
void solve(int pos,ll iz,ll de){
    if(pos==n){
        mini=min(mini,abs(iz-de));
        return;
    }
    solve(pos+1,iz+cost[pos],de);
    solve(pos+1,iz,de+cost[pos]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>n;
    cost.resize(n);
    for(int i=0;i<n;i++){
        cin >> cost[i];
    }
    solve(0,0,0);
    cout << mini;
}