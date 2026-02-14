#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a,b;
vector<pair<int,int>> graph[100000];
bitset<100000> usado,visited,respu;
vector<int> res;
void dfs(int now){
    int xd=-1;
    visited[now]=true;
    for(auto u:graph[now]){
        if(visited[u.first] && !usado[u.first]){
            usado[u.first]=true;
            res.push_back(u.second);
            respu[u.second]=true;
            continue;
        }
        if(usado[u.first]){
            xd=u.second;
            continue;
        }
        usado[u.first]=true;
        respu[u.second]=true;
        res.push_back(u.second);
        dfs(u.first);
    }
    if(xd!=-1 && !usado[now]){
        usado[now]=true;
        res.push_back(xd);
        respu[xd]=true;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        graph[--b].push_back({--a,i});
    }
    for(int i=0;i<n;i++){
        if(visited[i])continue;
        dfs(i);
    }
    cout << n-res.size() << endl;
    for(auto u:res)cout << u+1 << '\n';
    for(int i=0;i<n;i++){
        if(!respu[i])cout << i+1 << '\n';
    }
}