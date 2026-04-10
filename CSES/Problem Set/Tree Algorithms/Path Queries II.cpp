#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n,q,a,b,c,tiempo;
vector<int> val,head,bigchild,pos,depth,parent;
vector<vector<int>> graph;
struct segment{
    int tam;
    vector<int> st;
    int query(int l,int r){
        int res=0;
        for(l+=tam,r+=tam;l<=r && l>0;l>>=1,r>>=1){
            if(l&1)res=max(res,st[l++]);
            if(!(r&1))res=max(res,st[r--]);
        }
        return res;
    }
    void update(int ind,int a){
        for(st[ind+=tam]=a;ind>1;ind>>=1)st[ind>>1]=max(st[ind],st[ind^1]);
    }
    segment(vector<int> a){
        tam=a.size();
        st.resize(2*tam);
        for(int i=0;i<tam;i++)st[i+tam]=a[i];
        for(int i=tam-1;i>0;i--)st[i]=max(st[i<<1],st[i<<1|1]);
    }
};
void init(int x){
    tiempo=0;
    val.resize(x);
    head.resize(x);
    bigchild.resize(x);
    depth.resize(x);
    parent.resize(x);
    graph.resize(x);
    pos.resize(x);
}
int dfs(int node){
    int tam=1,tambig=0;
    bigchild[node]=-1;
    for(auto u:graph[node]){
        if(u==parent[node])continue;
        parent[u]=node;
        depth[u]=depth[node]+1;
        int tamu=dfs(u);
        if(tambig<tamu){
            tambig=tamu;
            bigchild[node]=u;
        }
        tam+=tamu;
    }
    return tam;
}
void descompose(int node,int h){
    head[node]=h;
    pos[node]=tiempo++;
    if(bigchild[node]!=-1)descompose(bigchild[node],h);
    for(auto u:graph[node]){
        if(u==parent[node] || u==bigchild[node])continue;
        descompose(u,u);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    init(n);
    for(int i=0;i<n;i++)cin >> val[i];
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0);
    descompose(0,0);
    vector<int> base(n);
    for(int i=0;i<n;i++)base[pos[i]]=val[i];
    segment clav(base);
    while(q--){
        cin >> a >> b >> c;
        a--,b--;c--;
        if(!a)clav.update(pos[b],c+1);
        else{
            int res=0;
            for(;head[b]!=head[c];c=parent[head[c]]){
                if(depth[head[b]]>depth[head[c]])swap(b,c);
                res=max(res,clav.query(pos[head[c]],pos[c]));
            }
            if(depth[b]>depth[c])swap(b,c);
            res=max(res,clav.query(pos[b],pos[c]));
            cout << res << ' ';
        }
    }
}