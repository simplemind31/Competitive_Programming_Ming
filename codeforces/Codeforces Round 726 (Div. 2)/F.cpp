#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,a,b;
bool bipar;
vector<bool> color;
vector<vector<ll>> graph;
vector<bool> visited;
vector<ll> val,tar,pad;
vector<ll> orden;
void dfs(ll node){
    visited[node]=true;
    for(auto u:graph[node]){
        if(visited[u]){
            if(color[u]==color[node])bipar=false;
            continue;
        }
        color[u]=!color[node];
        pad[u]=node;
        dfs(u);
    }
    orden.push_back(node);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // cada ciclo convierto en algo?

    // siempre usar los que no son articulation poll
    // dfs siempre genera eso?
    cin >> t;
    while(t--){
        bipar=true;
        cin >> n >> m;
        orden.clear();
        val.assign(n,0);
        pad.assign(n,0);
        tar=val;
        visited.assign(n,false);
        color=visited;
        graph.assign(n,{});
        for(ll i=0;i<n;i++)cin >> val[i];
        for(ll i=0;i<n;i++)cin >> tar[i];
        while(m--){
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }
        bool xd=true;
        dfs(0);
        for(ll i=0;i<n-1 && xd;i++){
            //cout << orden[i] << ' ';
            // usar en este orden
            ll u=pad[orden[i]];
            //cout << tar[orden[i]]-val[orden[i]] << '\n';
            val[u]+=tar[orden[i]]-val[orden[i]];
            val[orden[i]]+=tar[orden[i]]-val[orden[i]];
            /*for(ll j=0;j<n;j++)cout << val[j] << ' ';
            cout << endl;
            for(ll j=0;j<n;j++)cout << tar[j] << ' ';
            cout << endl;*/
        }
        if(val[0]!=tar[0])xd=false;
        //cout << 0 << ' ' << val[0] << ' ' << tar[0] << '\n';
        if(xd){
            cout << "YES\n";
            continue;
        }
        ll dif=abs(val[0]-tar[0]);
        if(dif&1){
            cout << "NO\n";
            continue;
        }
        // existe ciclo de tamaño impar?
        // biparty
        if(!bipar)cout << "YES\n";
        else cout << "NO\n";
    }
}