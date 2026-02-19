#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,a,b,con,maxi;
map<ll,int> respue;
map<ll,bool> visited;
ll solve(ll a,ll now){
    if(now>=10)return 1e9;
    if(a==b)return 0;
    if(a>b){
        if(a&1)return solve(2+((a+1)>>1),0);
    }
    if(respue[a]!=0)return respue[a];
    if(visited[a])return 1e9;
    visited[a]=true;
    ll res=1e9;
    if((a&1)==0)res=min(res,1+solve(a>>1,0));
    res=min(1+solve(a<<1,0),res);
    res=min(1+solve(a+1,now+1),res);
    return respue[a]=res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        respue.clear();
        visited.clear();
        cin >> a >> b;
        maxi=max(2*a,2*b);
        cout << solve(a,0) << '\n';
    }
}