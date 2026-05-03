#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n;
pair<ll,ll> dp[500][500];// cantidad de formas,la cantidad toooootal de formas(incluyendo subformas)
string st;
pair<ll,ll> solve(int l,int r){
    if((r-l+1)&1)return {0,0};
    if(r-l+1==2 && st[l]==st[r])return {1,1};
    if(r<=l)return {0,0};
    if(dp[l][r]!=make_pair(-1ll,-1ll))return dp[l][r];
    dp[l][r]={0,0};
    for(int i=l+1;i<r;i++){
        dp[l][r]=dp[l][r]+2*(solve(l,i).second*solve(i+1,r).second);
    }
    return dp[l][r];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fill(&dp[0][0],&dp[0][0]+500*500,make_pair(-1,-1));
    cin >> st;
    n=st.size();
    cout << solve(0,n-1).first;
}
// 00122122