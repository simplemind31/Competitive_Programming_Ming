#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll a,b,n;
ll solve(ll x,ll y){
    if(x==y)return 0;
    if(x>y){
        bool imp=x&1;
        return 1+imp+solve((x+imp)>>1,y);
    }else{
        bool imp=y&1;
        return min(y-x,1+imp+solve(x,(y-imp)>>1));
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << solve(a,b) << '\n';
    }
}