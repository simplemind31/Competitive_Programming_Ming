#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int color[100000],n,a,b,maxi[100000];
map<int,int> con[100001];
vector<int> graph[100000];
ll suma[100000],res[100000];
void dfs(int node,int ante){
    con[node][color[node]]=1;
    maxi[node]=1;
    suma[node]=color[node];
    for(auto u:graph[node]){
        if(u==ante)continue;
        dfs(u,node);
        if(con[u].size()>con[node].size()){
            swap(con[u],con[node]);
            swap(suma[u],suma[node]);
            swap(maxi[u],maxi[node]);
        }
        for(auto v:con[u]){
            con[node][v.first]+=v.second;
            if(con[node][v.first]>maxi[node]){
                maxi[node]=con[node][v.first];
                suma[node]=v.first;
            }else if(con[node][v.first]==maxi[node]){
                suma[node]+=v.first;
            }
        }
    }
    res[node]=suma[node];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)cin >> color[i];
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    for(int i=0;i<n;i++)cout << res[i] << ' ';
}