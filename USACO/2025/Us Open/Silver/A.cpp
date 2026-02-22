#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,a,b,c,q;
vector<ll> graph[100000];
pair<ll,ll> nums[100000];
vector<pair<ll,ll>> val[11];
// node, difi,excite
multiset<ll> aho;
void dfs(ll node,ll exci){
    exci+=nums[node].second;
    aho.insert(nums[node].first);
    // si solo tengo c=0, para usar este node necesito s>=--aho.end()
    // si tengo 1 necesito s>=----aho.end();
    // si tengo 2 necesito s>=------aho.end();
    auto p=aho.end();
    for(ll i=0;i<=10;i++){
        val[i].push_back({*(--p),exci});
    }
    for(auto u:graph[node])dfs(u,exci);
    aho.erase(aho.find(nums[node].first));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i=0;i<=10;i++)aho.insert(0);
    for(ll i=1;i<n;i++){
        cin >> a >> nums[i].first >> nums[i].second;
        graph[--a].push_back(i);
    }
    dfs(0,0);
    for(ll i=0;i<=10;i++){
        sort(ALL(val[i]));
        for(ll j=1;j<val[i].size();j++){
            val[i][j].second=max(val[i][j].second,val[i][j-1].second);
        }
    }
    cin >> q;
    while(q--){
        cin >> a >> b;
        cout << (--upper_bound(ALL(val[b]),make_pair(a,(ll)2e18)))->second << '\n';
    }
}