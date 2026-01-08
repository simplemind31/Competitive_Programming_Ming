#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
bool xd;
vector<int> graph[100000],res;
bitset<100000> usado,visitado;
stack<int> ahora;
void dfs(int now,int ante){
    visitado[now]=1;
    usado[now]=1;
    ahora.push(now);
    for(auto u:graph[now]){
        if(u==ante)continue;
        if(usado[u]){
            //encontre;
            xd=true;
            res.push_back(u);
            while(ahora.top()!=u){
                res.push_back(ahora.top());
                ahora.pop();
            }
            res.push_back(u);
            return;
        }
        dfs(u,now);
        if(xd)return;
    }
    usado[now]=0;
    ahora.pop();
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
    for(int i=0;i<n;i++){
        if(!visitado[i])dfs(i,-1);
        if(res.size()!=0){
            cout << res.size() << '\n';
            for(auto u:res)cout << u+1 << ' ';
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}