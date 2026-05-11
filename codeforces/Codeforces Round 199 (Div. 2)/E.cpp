#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a,b,tiempo,raiz;
queue<int> bfs;
vector<int> tin,depth,dist,red;
vector<vector<int>> graph,sparse;
void dfs(int node,int ante){
    sparse[tiempo][0]=node;
    tin[node]=tiempo++;
    for(auto u:graph[node]){
        if(u==ante)continue;
        depth[u]=depth[node]+1;
        dfs(u,node);
        sparse[tiempo++][0]=node;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    raiz=sqrt(k-1)+1;
    graph.resize(n);
    depth.resize(n);
    tin.resize(2*n);
    dist.assign(n,1e9);
    sparse.assign(2*n,vector<int>(20));
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    for(int j=1;j<20;j++){
        for(int i=0;i<2*n;i++){
            if(i+(1<<(j-1))>=2*n)continue;
            if(depth[sparse[i][j-1]]<depth[sparse[i+(1<<(j-1))][j-1]])sparse[i][j]=sparse[i][j-1];
            else sparse[i][j]=sparse[i+(1<<(j-1))][j-1];
        }
    }
    red.push_back(0);
    bfs.push(0);
    dist[0]=0;
    for(int q=1;q<=k;q++){
        cin >> a >> b;
        b--;
        if(a==1){
            dist[b]=0;
            bfs.push(b);
            red.push_back(b);
            continue;
        }
        int mini=dist[b];
        for(auto u:red){
            // distancia entre u y b
            int x=tin[u],y=tin[b];
            if(x>y)swap(x,y);
            int now=depth[u]+depth[b],lo=31-__builtin_clz(y-x+1);
            if(depth[sparse[x][lo]]<depth[sparse[y-(1<<lo)+1][lo]])now-=2*depth[sparse[x][lo]];
            else now-=2*depth[sparse[y-(1<<lo)+1][lo]];
            mini=min(mini,now);
        }
        cout << mini << '\n';
        if(q%raiz==0){
            while(!bfs.empty()){
                int top=bfs.front();
                bfs.pop();
                for(auto u:graph[top]){
                    if(dist[u]>dist[top]+1){
                        dist[u]=dist[top]+1;
                        bfs.push(u);
                    }
                }
            }
            red.clear();
        }
    }
}