#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t;
ll a,b;
vector<ll> nums;
void solve(int pos,int con,ll numero){
    if(pos==19){
        nums.push_back(numero);
        return;
    }
    solve(pos+1,con,numero*10);
    if(con<3){
        for(int i=1;i<10;i++){
            solve(pos+1,con+1,numero*10+i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve(0,0,0);
    nums.push_back(2e18);
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << upper_bound(ALL(nums),b)-lower_bound(ALL(nums),a) << '\n';
    }
}