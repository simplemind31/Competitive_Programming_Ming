#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,res=1e9;
vector<int> graph[100000];
bitset<100000> visited;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("fenceplan.in","r",stdin);
    freopen("fenceplan.out","w",stdout);
    cin >> n >> m;
    pair<int,int> cows[n];
    for(int i=0;i<n;i++){
        cin >> cows[i].first >> cows[i].second;
    }
    for(int i=0;i<m;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(visited[i])continue;
        visited[i]=true;
        int minix=1e9,miniy=1e9,maxix=-1e9,maxiy=-1e9;
        queue<int> bfs;
        bfs.push(i);
        while(!bfs.empty()){
            int top=bfs.front();
            bfs.pop();
            minix=min(minix,cows[top].first);
            miniy=min(miniy,cows[top].second);
            maxix=max(maxix,cows[top].first);
            maxiy=max(maxiy,cows[top].second);
            for(auto u:graph[top]){
                if(visited[u])continue;
                visited[u]=true;
                bfs.push(u);
            }
        }
        res=min(res,2*(maxix-minix+maxiy-miniy));
    }
    cout << res;
}