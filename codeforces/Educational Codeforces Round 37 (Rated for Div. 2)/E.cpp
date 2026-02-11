#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,a,b,con,dsu[200000],tam[200000];
vector<int> NOgraph[200000],res;
vector<pair<int,int>> graph[200000];
bitset<200000> visited;
int find(int a){return (a==dsu[a])?a:dsu[a]=find(dsu[a]);}
bool unite(int a,int b){
    if((a=find(a))==(b=find(b)))return false;
    if(tam[b]>tam[a])swap(a,b);
    tam[a]+=tam[b];
    dsu[b]=a;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        tam[dsu[i]=i]=1;
        NOgraph[i].push_back(i);
        NOgraph[i].push_back(n);
    }
    while(m--){
        cin >> a >> b;
        if(--a>--b)swap(a,b);
        NOgraph[a].push_back(b);
    }
    for(int i=0;i<n;i++){
        sort(ALL(NOgraph[i]));
        for(int j=1;j<NOgraph[i].size();j++){
            if(NOgraph[i][j-1]+1==NOgraph[i][j])continue;
            graph[i].push_back({NOgraph[i][j-1]+1,NOgraph[i][j]-1});
        }
    }
    for(int i=0;i<n;i++){
        if(visited[i])continue;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> posi;
        posi.push({i,i});
        while(!posi.empty()){
            pair<int,int> front=posi.top();
            posi.pop();
            if(!posi.empty() && posi.top().first==front.first)continue;
            if(front.first!=front.second)posi.push({front.first+1,front.second});
            int top=front.first;
            unite(top,i);
            if(visited[top])continue;
            visited[top]=true;
            for(auto u:graph[top])posi.push(u);
        }
    }
    for(int i=0;i<n;i++)if(i==find(i))res.push_back(tam[i]);
    sort(ALL(res));
    cout << res.size() << '\n';
    for(auto u:res)cout << u << ' ';
}