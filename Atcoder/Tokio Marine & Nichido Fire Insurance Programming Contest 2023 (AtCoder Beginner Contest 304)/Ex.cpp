#include <bits/stdc++.h>
#define imposi \
do{ \
    cout << "No"; \
    return 0; \
}while(0)
using namespace std;
int n,m,a,b;
struct cmp{
    bool operator()(const pair<pair<int,int>,int>& a,const pair<pair<int,int>,int>& b)const{
        if(a.first.second==b.first.second)return a.first.first<b.first.first;
        return a.first.second<b.first.second;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<int> graph[n],deg(n),res(n),deg2(n),ne[n],topo;
    pair<int,int> rango[n];
    priority_queue<pair<pair<int,int>,int>> disponible;
    priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,cmp> posible;
    queue<int> cola;
    while(m--){
        cin >> a >> b;
        graph[--b].push_back(--a);
        ne[a].push_back(b);
        deg[a]++;
        deg2[b]++;
    }
    for(int i=0;i<n;i++){
        cin >> rango[i].first >> rango[i].second;
        if(!deg2[i])cola.push(i);
    }
    while(!cola.empty()){
        int top=cola.front();
        cola.pop();
        topo.push_back(top);
        for(auto u:ne[top])if(--deg2[u]==0)cola.push(u);
    }
    for(auto u:topo)for(auto v:ne[u])rango[v].first=max(rango[v].first,rango[u].first+1);
    for(int i=0;i<n;i++)if(!deg[i])disponible.push({{rango[i].second,rango[i].first},i});
    int con=n;
    while(!disponible.empty() && disponible.top().first.first>=con){
        posible.push(disponible.top());
        disponible.pop();
    }
    while(!posible.empty()){
        pair<pair<int,int>,int> top=posible.top();
        posible.pop();
        if(top.first.second>con)imposi;
        res[top.second]=con--;
        for(auto u:graph[top.second])if(--deg[u]==0)disponible.push({{rango[u].second,rango[u].first},u});
        while(!disponible.empty() && disponible.top().first.first>=con){
            posible.push(disponible.top());
            disponible.pop();
        }
    }
    if(con!=0)imposi;
    cout << "Yes\n";
    for(int i=0;i<n;i++)cout << res[i] << ' ';
}