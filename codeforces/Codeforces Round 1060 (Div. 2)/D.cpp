#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool can;
int t,n,m,a,b;
vector<bool> par,partecamino;
vector<int> cami;
vector<string> op;
vector<vector<int>> graph;
void dfs(int now,int ante){
    partecamino[now]=now==n-1;
    for(auto u:graph[now]){
        if(u==ante)continue;
        par[u]=!par[now];
        dfs(u,now);
        if(partecamino[u])partecamino[now]=true;
    }
    if(partecamino[now]){
        cami.push_back(now);
        return;
    }
    if(!op.empty() && op.back()!="1"){
        op.push_back("1");
        can=!can;
    }
    if(par[now]==can){
        op.push_back("1");
        can=!can;
    }
    op.push_back("2 "+to_string(now+1));
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        can=0;
        cin >> n;
        op.clear();
        graph.clear();
        graph.resize(n);
        par.clear();
        par.resize(n);
        partecamino=par;
        cami.clear();
        for(int i=1;i<n;i++){
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }
        dfs(0,-1);
        while(cami.size()>1){
            if(!op.empty() && op.back()!="1"){
                op.push_back("1");
                can=!can;
            }
            if(par[cami.back()]==can){
                op.push_back("1");
                can=!can;
            }
            op.push_back("2 "+to_string(cami.back()+1));
            cami.pop_back();
        }
        cout << op.size() << '\n';
        for(auto u:op)cout << u << '\n';
        cout << '\n';
    }
}