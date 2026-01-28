#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
ll x,y,n,A;
map<ll,long double> dp;
//minimum to make a 0;
long double solve(ll a){
    if(a==0)return 0;
    if(dp[a]!=0)return dp[a];
    dp[a]=x+solve(a/A);
    long double ex=0;
    for(int i=2;i<=6;i++){
        ex+=y+solve(a/i);
    }
    // (ex+a)/6=a
    ex+=y;
    ex/=5;
    return dp[a]=min(dp[a],ex);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> A >> x >> y;
    cout << fixed << setprecision(12) << solve(n);
}