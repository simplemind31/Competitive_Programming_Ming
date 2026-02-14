#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool xd;
ll n,m,t,a,b,c,maxi,res;
vector<bool> visited,parasito;
vector<ll> nums;
vector<vector<pair<ll,bool>>> graph;
void dfs(ll node){
    visited[node]=true;
    nums.push_back(node);
    if(parasito[node])maxi++;
    for(auto u:graph[node]){
        if(visited[u.first]){
            // 0,1->1
            // 1,1->0
            // 0,0->0
            if((parasito[node]^u.second)!=parasito[u.first])maxi=-1e18;
        }else{
            parasito[u.first]=parasito[node]^u.second;
            dfs(u.first);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        res=0;
        cin >> n >> m;
        graph.clear();
        graph.resize(n);
        visited.clear();
        visited.resize(n);
        parasito.clear();
        parasito.resize(n);
        while(m--){
            cin >> a >> b >> c;
            // si apunta a uno, es con 1 es porque es parasito
            // b->c ==1, si b es human, c es parasito, sino human
            // b->c ==0, si b es human, c es human, sino parasito
            // b->c ==1, si c es human, b es parasito  por acusar mal
            a--;b--;c--;
            graph[b].push_back({c,1-a});
            graph[c].push_back({b,1-a});
        }
        for(ll i=0;i<n && res>=0;i++){
            if(visited[i])continue;
            // i no es parasito
            maxi=0;
            dfs(i);
            ll temp1=maxi;
            maxi=0;
            while(nums.size()){
                visited[nums.back()]=false;
                parasito[nums.back()]=false;
                nums.pop_back();
            }
            parasito[i]=true;
            dfs(i);
            ll temp2=maxi;
            nums.clear();
            // i es parasito
            res+=max(temp1,temp2);
        }
        if(res<0)res=-1;
        cout << res << '\n';
    }
}