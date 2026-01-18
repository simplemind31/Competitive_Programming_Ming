#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
ll n,m,l,s,t,a,b,c;
vector<pair<ll,ll>> graph[200000];
bitset<200000> posi;
void solve(ll node, ll suma,ll lon){
    if(suma>t)return;
    if(lon==l){
        if(suma>=s)posi[node]=true;
        return;
    }
    for(auto u:graph[node])solve(u.first,suma+u.second,lon+1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> l >> s >> t;
    while(m--){
        cin >> a >> b >> c;
        graph[--a].push_back({--b,c});
    }
    solve(0,0,0);
    for(int i=0;i<n;i++)if(posi[i])cout << i+1 << ' ';
    cout << '\n';
}
