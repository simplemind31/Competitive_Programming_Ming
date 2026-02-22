#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200000;
int n,k,a,b,val[MAXN],sig1[MAXN],pad[MAXN],maximos[MAXN],maxiraiz[MAXN][2],maxihiji[MAXN][2];
ll solve2[MAXN],raiz[MAXN];
vector<int> graph[MAXN];
ll dfs1(int node,int ante){
    ll maxi=0;
    for(auto u:graph[node]){
        if(u==ante)continue;
        pad[u]=node;
        ll temp=dfs1(u,node);
        if(temp>maxi){
            maxi=temp;
            sig1[node]=u;
        }
    }
    if(maxi==0)sig1[node]=node;
    return val[node]+maxi;
}
ll resfinal2;
vector<int> res2,temp2;
void dfs2(int node,int ante){
    solve2[node]=val[node];
    ll maxi=0;
    maximos[node]=node;
    for(auto u:graph[node]){
        if(u==ante)continue;
        solve2[node]+=val[u];
        dfs2(u,node);
        if(solve2[u]-val[u]>=maxi){
            maxi=solve2[u]-val[u];
            maximos[node]=maximos[u];
        }
    }
    solve2[node]+=maxi;
}
int usadoraiz[200000],usadohiji[200000];
void solveraiz(int node,int ante){
    // suma de un lado raiz otro lado dfs
    ll maxi[2],maxidfs[2];
    maxi[0]=maxi[1]=maxidfs[0]=maxidfs[1]=0;
    maxiraiz[node][0]=maxiraiz[node][1]=-1;
    maxihiji[node][0]=maxihiji[node][1]=-1;
    raiz[node]=val[node];
    for(auto u:graph[node]){
        if(u==ante)continue;
        raiz[node]+=val[u];
        solveraiz(u,node);
        if(raiz[u]-val[u]>=maxi[0]){
            maxi[1]=maxi[0];
            maxiraiz[node][1]=maxiraiz[node][0];
            maxi[0]=raiz[u]-val[u];
            maxiraiz[node][0]=u;
        }else if(raiz[u]-val[u]>=maxi[1]){
            maxi[1]=raiz[u]-val[u];
            maxiraiz[node][1]=u;
        }
        if(solve2[u]-val[u]>=maxidfs[0]){
            maxidfs[1]=maxidfs[0];
            maxihiji[node][1]=maxihiji[node][0];
            maxidfs[0]=solve2[u]-val[u];
            maxihiji[node][0]=u;
        }else if(solve2[u]-val[u]>=maxidfs[1]){
            maxidfs[1]=solve2[u]-val[u];
            maxihiji[node][1]=u;
        }
    }
    if(maxihiji[node][0]!=maxiraiz[node][0]){
        //usar los dos mejores;
        raiz[node]+=maxidfs[0]+maxi[0];
        usadoraiz[node]=maxiraiz[node][0];
        usadohiji[node]=maxihiji[node][0];
    }else if(maxihiji[node][0]!=maxiraiz[node][1] && maxihiji[node][1]!=maxiraiz[node][0]){
        if(maxidfs[1]+maxi[0]>=maxidfs[0]+maxi[1]){
            usadoraiz[node]=maxiraiz[node][0];
            usadohiji[node]=maxihiji[node][1];
        }else{
            usadoraiz[node]=maxiraiz[node][1];
            usadohiji[node]=maxihiji[node][0];
        }
        raiz[node]+=max(maxidfs[1]+maxi[0],maxidfs[0]+maxi[1]);
    }else if(maxihiji[node][0]!=maxiraiz[node][1]){
        raiz[node]+=maxidfs[0]+maxi[1];
        usadoraiz[node]=maxiraiz[node][1];
        usadohiji[node]=maxihiji[node][0];
    }else if(maxihiji[node][1]!=maxiraiz[node][0]){
        raiz[node]+=maxidfs[1]+maxi[0];
        usadoraiz[node]=maxiraiz[node][0];
        usadohiji[node]=maxihiji[node][0];
    }else{
        // solo ir al raiz
        raiz[node]+=maxi[0];
        usadoraiz[node]=maxiraiz[node][0];
        usadohiji[node]=-1;
    }
}
vector<int> supermegares;
void simularvuelta(int node,int ante,bool dearriba){
    if(dearriba)supermegares.push_back(node);
    for(auto u:graph[node]){
        if(u==ante)continue;
        if(maximos[u]==maximos[node])simularvuelta(u,node,!dearriba);
    }
    if(!dearriba)supermegares.push_back(node);
}
void simular(int node,int ante){
    supermegares.push_back(node);
    if(usadohiji[node]!=-1)simularvuelta(usadohiji[node],node,false);
    for(auto u:graph[node]){
        if(u==usadoraiz[node] || u==ante || u==usadohiji[node])continue;
        supermegares.push_back(u);
    }
    if(usadoraiz[node]!=-1 && usadoraiz[node]!=node)simular(usadoraiz[node],node);
}
int condis=0;
ll suma3;
vector<int> res3;
void dfs3(int node,int ante){
    bool xd=false;
    if(condis==3){
        res3.push_back(node);
        suma3+=val[node];
        condis=0;
        xd=true;
    }
    for(auto u:graph[node]){
        if(u==ante)continue;
        condis++;
        dfs3(u,node);
    }
    if(!xd){
        condis=0;
        suma3+=val[node];
        res3.push_back(node);
    }
    condis++;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++)cin >> val[i];
    if(k==1){
        cout << dfs1(0,-1) << '\n';
        vector<int> res;
        int now=0;
        while(now!=sig1[now]){
            res.push_back(now);
            now=sig1[now];
        }
        res.push_back(now);
        cout << res.size() << '\n';
        for(auto u:res)cout << u+1 << ' ';
        return 0;
    }else if(k==2){
        // toda distancia impar es primero hijo luego nodo
        // toda distancia par es nodo luego hijo
        // pueden decidir volver o no

        // op1 elegir un camino recto  y sumar los que estan a distancia <=1 de ese camino
        // para comprobar mi teoria



        //ir primero a un hijo, luego volver y setear a otro hijo como raiz(volviendo al problema original)
        //elegir dfs de un hijo y luego raiz de otro hijo
        // dfs=mayor suma si regreso luego
        // raiz=mayor suma si no regreso
        dfs2(0,-1);
        solveraiz(0,-1);
        simular(0,-1);
        /*for(int i=0;i<n;i++){
            cout << usadoraiz[i]+1 << ' ';
        }
        cout << '\n';
        for(int i=0;i<n;i++){
            cout << usadohiji[i]+1 << ' ';
        }
        cout << '\n';
        for(int i=0;i<n;i++){
            cout << maximos[i]+1 << ' ';
        }
        cout << '\n';*/
        cout << raiz[0] << '\n' << supermegares.size() << '\n';
        for(auto u:supermegares)cout << u+1 << ' ';
        return 0;
    }else{
        condis=3;
        dfs3(0,-1);
        cout << suma3 << '\n';
        cout << res3.size() << '\n';
        for(auto u:res3)cout << u+1 << ' ';
        return 0;
    }
}