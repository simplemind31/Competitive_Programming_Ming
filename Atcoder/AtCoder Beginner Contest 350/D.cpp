#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<long long> vll;
ll n,m,a,b,suma,con,res;
vector<ll> graph[200000];
bitset<200000> visited;
void dfs(ll now){
    suma+=graph[now].size();
    con++;
    visited[now]=true;
    for(auto u:graph[now]){
        if(visited[u])continue;
        dfs(u);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    for(ll i=0;i<n;i++){
        if(visited[i])continue;
        con=suma=0;
        dfs(i);
        suma/=2;
        res+=con*(con-1)/2-suma;
    }
    cout << res;
}