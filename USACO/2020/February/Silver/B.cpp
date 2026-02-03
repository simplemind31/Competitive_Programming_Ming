#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n;
vector<ll> alt[20001],hori[20001],psumhori[20001],psumalt[20001];
ll res=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("triangles.in","r",stdin);
    freopen("triangles.out","w",stdout);
    cin >> n;
    //-1e4->0
    pair<ll,ll> polls[n];
    for(ll i=0;i<n;i++){
        cin >> polls[i].first >> polls[i].second;
        polls[i].first+=1e4;
        polls[i].second+=1e4;
        alt[polls[i].second].push_back(polls[i].first);
        hori[polls[i].first].push_back(polls[i].second);
    }
    // cada i=right triangle;
    for(ll i=0;i<=20000;i++){
        sort(ALL(alt[i]));
        psumalt[i].resize(alt[i].size());
        if(alt[i].size())psumalt[i][0]=alt[i][0];
        for(ll j=1;j<alt[i].size();j++)psumalt[i][j]=(psumalt[i][j-1]+alt[i][j])%MOD;
        sort(ALL(hori[i]));
        psumhori[i].resize(hori[i].size());
        if(hori[i].size())psumhori[i][0]=hori[i][0];
        for(ll j=1;j<hori[i].size();j++)psumhori[i][j]=(psumhori[i][j-1]+hori[i][j])%MOD;
    }
    for(ll i=0;i<n;i++){
        ll pos=lower_bound(ALL(alt[polls[i].second]),polls[i].first)-alt[polls[i].second].begin();
        // psumalt[polls[i].second][pos]=izquierda
        ll iz=(((pos+1)*polls[i].first)%MOD)-psumalt[polls[i].second][pos];
        ll de=(psumalt[polls[i].second].back()-psumalt[polls[i].second][pos])-(((alt[polls[i].second].size()-pos-1)*polls[i].first)%MOD);
        pos=lower_bound(ALL(hori[polls[i].first]),polls[i].second)-hori[polls[i].first].begin();
        ll ab=(((pos+1)*polls[i].second)%MOD)-psumhori[polls[i].first][pos];
        ll arr=(psumhori[polls[i].first].back()-psumhori[polls[i].first][pos])-(((hori[polls[i].first].size()-pos-1)*polls[i].second)%MOD);
        res+=iz*ab+iz*arr+de*ab+de*arr;
    }
    cout << (res%MOD+MOD)%MOD;
}