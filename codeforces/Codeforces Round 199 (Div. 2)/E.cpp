#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a,b;
vector<vector<int>> graph;
struct segment{
    int tam;
    vector<int> a;
    vector<pair<int,int>> st,lazy;
    pair<int,int> merge(pair<int,int> x,pair<int,int> y){return {min(x.first,y.first),max(x.second,y.second)};}
    void build(int node,int l,int r){
        if(l==r){
            st[node]={a[l],a[l]};
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=merge(st[hiji],st[hijd]);
    }
    void push_down(int node,int l,int r){
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(l!=r){
            lazy[hiji]=merge(lazy[hiji],lazy[node]);
            lazy[hijd]=merge(lazy[hijd],lazy[node]);
        }
        st[node]=merge(st[node],lazy[node]);
        lazy[node]={1e9,-1e9};
    }
    void update(int node,int l,int r,int i,int j,int val){
        push_down(node,l,r);
        if(r<i || j<l)return;
        if(i<=l && r<=j){
            lazy[node]={val,val};
            push_down(node,l,r);
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        update(hiji,l,mid,i,j,val);
        update(hijd,mid+1,r,i,j,val);
        st[node]=merge(st[hiji],st[hijd]);
    }
    pair<int,int> query(int node,int l,int r,int i,int j){
        push_down(node,l,r);
        if(r<i || j<l)return {1e9,-1e9};
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return merge(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    segment(vector<int> x){
        tam=x.size();
        a=x;
        st.resize(4*tam+5);
        lazy.assign(4*tam+5,{1e9,-1e9});
        build(0,0,tam-1);
    }
};
int tiempo;
vector<int> pad,depth,bigchild,pos,head,tin,tout;
int dfs(int node){
    tin[node]=tiempo++;
    int tam=1,tambig=0;
    bigchild[node]=-1;
    for(auto u:graph[node]){
        if(u==pad[node])continue;
        pad[u]=node;
        depth[u]=depth[node]+1;
        int tamu=dfs(u);
        tam+=tamu;
        if(tamu>tambig){
            tambig=tamu;
            bigchild[node]=u;
        }
    }
    tout[node]=tiempo-1;
    return tam;
}
void descompose(int node,int h){
    head[node]=h;
    pos[node]=tiempo++;
    if(bigchild[node]!=-1)descompose(bigchild[node],h);
    for(auto u:graph[node]){
        if(u==pad[node] || u==bigchild[node])continue;
        descompose(u,u);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    graph.resize(n);
    pad.resize(n);
    tin=tout=head=pos=bigchild=depth=pad;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0);
    tiempo=0;
    descompose(0,0);
    /*for(int i=0;i<n;i++){
        cout << tin[i] << ' ';
    }
    cout << endl;
    for(int i=0;i<n;i++){
        cout << tout[i] << ' ';
    }*/
    segment euler(vector<int>(n,-1e9));
    segment camino(vector<int>(n,1e9));
    euler.update(0,0,n-1,tin[0],tout[0],depth[0]);
    camino.update(0,0,n-1,pos[0],pos[0],depth[0]);
    // hijos updatean a los padres con camino
    // tengo que update depth[now]-depth[pad] para cada pad
    // el padre updatean a los hijos con euler
    // euler esta bien, pero que pasa si e hijo de algun ancestro tiene menor distancia
    // min(depth[b]-depth[x]+euler[x]); donde x esta en el camino del b al 0
    // depth[b]+min(min(depth de algun hijo de[x])=euler[x]-depth[x])
    while(k--){
        cin >> a >> b;
        b--;
        if(a==2){
            int arr=camino.query(0,0,n-1,pos[b],pos[b]).first;//minimo depth del hijo
            int abb=euler.query(0,0,n-1,tin[b],tin[b]).second;// max depth del pad
            cout << min(arr-depth[b],depth[b]-abb) << '\n';
            continue;
        }
        euler.update(0,0,n-1,tin[b],tout[b],depth[b]);
        // camino del b al 0
        for(;head[b]!=head[0];b=pad[head[b]]){
            camino.update(0,0,n-1,pos[head[b]],pos[b],depth[b]);
        }
        camino.update(0,0,n-1,pos[0],pos[b],depth[b]);
    }
}