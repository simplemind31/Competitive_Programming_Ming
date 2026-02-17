#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,mat[250][250],con[250][250],ahor,res2,res1;
vector<pair<int,int>> nodos;// color, cantidad
pair<int,int> pad[250][250],now;
bitset<250> visited[250];
vector<vector<int>> graph;
unordered_map<ll,bool> usado;
void fill(int x,int y,int color){
    if(x<0 || y<0 || x>=n || y>=n)return;
    if(visited[x][y] || mat[x][y]!=color)return;
    visited[x][y]=true;
    pad[x][y]=now;
    fill(x-1,y,color);
    fill(x+1,y,color);
    fill(x,y-1,color);
    fill(x,y+1,color);
}
int solve(int node,int color){
    if(usado[node*1e7+color])return 0;
    usado[node*1e7+color]=true;
    int tam=nodos[node].second;
    for(auto u:graph[node]){
        if(nodos[u].first==color){
            tam+=solve(u,nodos[node].first);
        }
    }
    return tam;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("multimoo.in","r",stdin);
    freopen("multimoo.out","w",stdout);
    cin >> n;
    // compress the colors
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i][j];
        }
    }
    //hallar los componentes
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j])continue;
            now={i,j};
            fill(i,j,mat[i][j]);
        }
    }
    set<pair<int,int>> edges;
    // hallar tamaño de cada componente
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res1=max(res1,++con[pad[i][j].first][pad[i][j].second]);
        }
    }
    //transformar mat en grafo donde cada componente es un nodo de forma {color, cantidad}
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(pad[i][j]==make_pair(i,j)){
                nodos.push_back({mat[i][j],con[i][j]});
                mat[i][j]=ahor++;
            }else mat[i][j]=0;
        }
    }
    //añadir aristas a los nodos
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // unir padres
            if(i-1>=0 && pad[i-1][j]!=pad[i][j]){
                pair<int,int> pa1=pad[i-1][j],pa2=pad[i][j];
                edges.insert({min(mat[pa1.first][pa1.second],mat[pa2.first][pa2.second]),max(mat[pa1.first][pa1.second],mat[pa2.first][pa2.second])});
            }
            if(j-1>=0 && pad[i][j-1]!=pad[i][j]){
                pair<int,int> pa1=pad[i][j-1],pa2=pad[i][j];
                edges.insert({min(mat[pa1.first][pa1.second],mat[pa2.first][pa2.second]),max(mat[pa1.first][pa1.second],mat[pa2.first][pa2.second])});
            }
            if(j+1<n && pad[i][j+1]!=pad[i][j]){
                pair<int,int> pa1=pad[i][j+1],pa2=pad[i][j];
                edges.insert({min(mat[pa1.first][pa1.second],mat[pa2.first][pa2.second]),max(mat[pa1.first][pa1.second],mat[pa2.first][pa2.second])});
            }
            if(i+1<n && pad[i+1][j]!=pad[i][j]){
                pair<int,int> pa1=pad[i+1][j],pa2=pad[i][j];
                edges.insert({min(mat[pa1.first][pa1.second],mat[pa2.first][pa2.second]),max(mat[pa1.first][pa1.second],mat[pa2.first][pa2.second])});
            }
        }
    }

    n=nodos.size();

    cout << res1 << '\n';
    graph.resize(n);
    for(auto u:edges){
        graph[u.first].push_back(u.second);
        graph[u.second].push_back(u.first);
    }
    // op2
    // usado[nodo actual][color diferente]
    // hay a lo mucho n^2 colores diferentes, y hay
    // para cada nodo, checkeo los que le unen y cual produce máximo
    
    for(int i=0;i<n;i++){
        for(auto u:graph[i]){
            // usar color de i y de u,
            res2=max(res2,solve(i,nodos[u].first));
        }
    }
    cout << res2;




    // op1
    // por cada edge, elijo esos dos colores, veo si fueron elegidos antes, y empezar a unir
    // hay aprox <= 4*n^2 edges,
}