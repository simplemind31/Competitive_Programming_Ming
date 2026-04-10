#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1000000;
bool xd=true;
int visited[MAXN+1],s,f,n,a,b,c,m,tiempo,dist[22][MAXN+1],val[MAXN+1],pad[MAXN+1],necesito[MAXN+1],correspond[MAXN+1];
vector<pair<int,int>> graph[MAXN+1];
ll res[(1<<(22))*22+22+1];
vector<int> block,buckets[22];
bitset<(1<<(22))*22+22+1> visitado;
void dfs1(int node){
    for(auto u:graph[node]){
        if(u.first==pad[node])continue;
        val[u.first]=u.second;
        pad[u.first]=node;
        if(u.second!=-1){
            block.push_back(u.first);
            correspond[u.first]=block.size()-1;
        }
        dfs1(u.first);
    }
}
void dfs2(int node){
    // para desbloquear cada uno necesito prerequisitos(necesito)
    // necesito desbloquear al padre y al actual
    if(visited[node]==1)xd=false;
    if(visited[node]!=0)return;
    visited[node]=1;
    if(pad[node]!=-1){
        dfs2(pad[node]);
        if(!xd)return;
        necesito[node]|=necesito[pad[node]];
        if(val[pad[node]]!=-1)necesito[node]|=1<<correspond[pad[node]];
    }
    if(val[node]!=-1){
        // necesito desbloquear val[node]
        dfs2(val[node]);
        if(!xd)return;
        necesito[node]|=necesito[val[node]];
        if(val[val[node]]!=-1)necesito[node]|=1<<correspond[val[node]];
        // si necesito bloq antes para desbloquear bloq->absurd;pero si no esta en el camino?
        if(necesito[node]&(1<<correspond[node])){
            xd=false;
            return;
        }
    }
    visited[node]=2;
}
// minima cantidad para desboquear subset y terminar en block[i]?
// a que block puedo desbloquear si tengo actual?2^m*m
// tengo todos los requisitos para desbloquear el que tengo que desbloquear 
//dijkstra?
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> s >> f;
    s--;f--;
    for(int i=0;i<=n;i++)correspond[i]=val[i]=pad[i]=-1;
    for(int i=1;i<n;i++){
        cin >> a >> b >> c;
        a--;b--;c--;
        if(a==f && c==-1)c=b;
        if(b==f && c==-1)c=a;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    // añado uno extra
    graph[n].push_back({s,n});
    graph[s].push_back({n,n});
    dfs1(n);
    m=block.size();
    if(m==0){
        int conta=0;
        while(f!=n){
            conta++;
            f=pad[f];
        }
        cout << conta;
        return 0;
    }
    int now=f;
    dfs2(f);
    if(s==f){
        cout << 0;
        return 0;
    }
    if(!xd){
        cout << -1;
        return 0;
    }
    //cout << '\n';
    //calcular distancia desde cada block[j] a todos;
    for(int i=0;i<m;i++){
        //dfs3(pad[block[i]],i,-1);
        queue<int> bfs;
        bfs.push(pad[block[i]]);
        while(!bfs.empty()){
            int top=bfs.front();
            bfs.pop();
            for(auto u:graph[top]){
                if(dist[i][u.first]!=0)continue;
                dist[i][u.first]=dist[i][top]+1;
                bfs.push(u.first);
            }
        }
        dist[i][pad[block[i]]]=0;
        //for(ll j=0;j<=n;j++)cout << dist[i][j] << ' ';
        //cout << endl;
    }
    fill(res,res+((1<<22)*22+22+1),1e18);
    // desbloquea subset x y termina en el nodo y
    // nuestra respuesta es 
    // caso base, para desbloquear solo el start me cuesta 0
    // termino en padre del block[i];
    res[(1<<0)*m+0]=0;
    //cout << endl << endl;
    for(int i=0;i<(1<<m);i++){
        buckets[__builtin_popcount(i)].push_back(i);
    }
    ll supermegares=1e18;
    for(int i=0;i<=m;i++){
        for(auto x:buckets[i]){
            for(int y=0;y<m;y++){
                if(y==correspond[f])supermegares=min(supermegares,res[x*m+y]);
                if(!(x&(1<<y)))continue;
                for(int j=0;j<m;j++){
                    if(x&(1<<j))continue;
                    //necesito necesito[block[j]] y tengo x
                    if(necesito[block[j]]-(necesito[block[j]]&x))continue;
                    // no era posible porwue necesitaba mas cosas
                    // ir desde block[y] al val[block[j]] y de val[block[j]] al block[j];
                    ll temp=dist[y][val[block[j]]]+dist[j][val[block[j]]]+res[x*m+y];
                    if(temp<res[(x|(1<<j))*m+j]){
                        res[(x|(1<<j))*m+j]=temp;
                    }
                }
            }
        }
    }
    if(supermegares==1e18)supermegares=-1;
    cout << supermegares;
}