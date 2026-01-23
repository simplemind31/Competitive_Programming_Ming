#include <bits/stdc++.h>
using namespace std;
bool xd=true,visited[200000];
int n,m,a,b,con;
vector<int> graph[200000];
void solve(int now,int ant){
    if(visited[now] || !xd)return;
    visited[now]=true;
    con++;
    if(graph[now].size()>2){
        xd=false;
        return;
    }
    for(auto u:graph[now]){
        if(u==ant)continue;
        solve(u,now);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    if(n!=m){
        cout << "No";
        return 0;
    }
    while(cin>>a>>b){
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    solve(0,-1);
    if(!xd || con!=n)cout << "No";
    else cout << "Yes";
}