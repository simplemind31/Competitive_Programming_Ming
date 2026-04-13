#include <bits/stdc++.h>
using namespace std;
char c;
int n,m,color,res;
vector<vector<bool>> visited;
vector<vector<int>> mat;
void flood(int x,int y,bool xd){
    if(x<0 || x>=n || y<0 || y>=m)return;
    if(visited[x][y] || (mat[x][y]!=xd))return;
    //cout << x << ' ' << y << ' ' << color << '\n';
    visited[x][y]=true;
    mat[x][y]=color;
    flood(x-1,y,xd);
    flood(x+1,y,xd);
    flood(x,y-1,xd);
    flood(x,y+1,xd);
}
vector<bool> used;
vector<int> iz,de;
vector<vector<int>> graph,g;
void dfs(int node,bool xd){
    if(used[node])return;
    used[node]=true;
    if(xd)iz.push_back(node);
    else de.push_back(node);
    for(auto u:graph[node])dfs(u,!xd);
}
vector<int> ind,mt;
bool try_kuhn(int node){
    if(used[node])return false;
    used[node]=true;
    for(auto u:g[node]){
        if(mt[u]==-1 || try_kuhn(mt[u])){
            mt[u]=node;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //biparty, minimum cover=maximum matching
    cin >> n >> m;
    mat.assign(n,vector<int>(m));
    visited.assign(n,vector<bool>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> c;
            mat[i][j]=c-'0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j])continue;
            //cout << i << ' ' << j << ' ' << mat[i][j] << ' ' << color << '\n';
            flood(i,j,mat[i][j]);
            color++;
            /*for(int k=0;k<n;k++){
                for(int l=0;l<m;l++){
                    cout << mat[k][l];
                }
                cout << '\n';
            }
            cout << endl << endl;*/
        }
    } 
    //cout << color << ' ';
    graph.resize(color);
    ind.resize(color);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i && mat[i][j]!=mat[i-1][j])graph[mat[i][j]].push_back(mat[i-1][j]);
            if(j && mat[i][j]!=mat[i][j-1])graph[mat[i][j]].push_back(mat[i][j-1]);
            if(i+1<n && mat[i][j]!=mat[i+1][j])graph[mat[i][j]].push_back(mat[i+1][j]);
            if(j+1<m && mat[i][j]!=mat[i][j+1])graph[mat[i][j]].push_back(mat[i][j+1]);
        }
    }
    n=color;
    used.resize(n);
    dfs(0,1);
    g.resize(iz.size());
    for(int i=0;i<iz.size();i++)ind[iz[i]]=i;
    for(int i=0;i<de.size();i++){
        ind[de[i]]=i;
        de[i]=i;
    }
    for(int i=0;i<iz.size();i++){
        for(auto u:graph[iz[i]]){
            g[i].push_back(ind[u]);
        }
        iz[i]=i;
    }
    mt.resize(de.size(),-1);
    for(int i=0;i<iz.size();i++){
        used.assign(iz.size(),0);
        if(try_kuhn(i))res++;
    }
    // uir parte 1 con parte 2;
    cout << res;
}