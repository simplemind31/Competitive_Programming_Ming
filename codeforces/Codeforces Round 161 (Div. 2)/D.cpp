#include <bits/stdc++.h>
using namespace std;
int n,m,k,a,b;
bool xd=false;
vector<int> graph[100000];
bitset<100000> unid,usado;
vector<int> res;
vector<int> posi;
void dfs(int now,int ante){
    res.push_back(now);
    usado[now]=true;
    if(res.size()>=k+1 && unid[now]){
        xd=true;
        return;
    }
    for(auto u:graph[now]){
        if(u==ante)continue;
        if(usado[u]){
            posi.push_back(u);
            continue;
        }
        dfs(u,now);
        if(xd)return;
    }
    usado[now]=false;
    res.pop_back();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    while(m--){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
        if(a==0)unid[b]=1;
        if(b==0)unid[a]=1;
    }
    dfs(0,-1);
    if(res.size()>k){
        cout << res.size() << '\n';
        for(int i=0;i<res.size();i++){
            cout << res[i]+1 << ' ';
        }
        return 0;
    }
    unid=0;
    for(auto u:graph[posi[0]]){
        unid[u]=1;
    }
    dfs(posi[0],-1);
    cout << res.size() << '\n';
    for(int i=0;i<res.size();i++){
        cout << res[i]+1 << ' ';
    }
}