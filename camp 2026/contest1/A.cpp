#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
struct segment{
    int tam;
    vector<int> st,a;
    void build(int node,int l,int r){
        if(l==r){
            st[node]=a[l];
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=st[hiji]^st[hijd];
    }
    void update(int node,int l,int r,int pos,int val){
        if(l==r){
            st[node]=val;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
        st[node]=st[hiji]^st[hijd];
    }
    int query(int node,int l,int r,int i,int j){
        if(r<i || j<l)return 0;
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return query(hiji,l,mid,i,j)^query(hijd,mid+1,r,i,j);
    }
    segment(vector<int> nums){
        a=nums;
        tam=nums.size();
        st.resize(4*tam+5);
        build(0,0,tam-1);
    }
};
int n,q,a,b,c,tiempo;
vector<int> val,head,pos,parent,bigchild,depth;
vector<vector<int>> graph;
int dfs(int node){
    int tam=1,tambig=0;
    bigchild[node]=-1;
    for(auto u:graph[node]){
        if(u==parent[node])continue;
        depth[u]=depth[node]+1;
        parent[u]=node;
        int tamu=dfs(u);
        if(tamu>tambig){
            tambig=tamu;
            bigchild[node]=u;
        }
        tam+=tamu;
    }
    return tam;
}
void descompose(int node,int h){
    pos[node]=tiempo++;
    head[node]=h;
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
    val.resize(n);
    depth=head=pos=parent=bigchild=val;
    graph.resize(n);
    for(int i=0;i<n;i++){
        cin >> val[i];
    }
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
        if(a==1){
            b--;
            // update
            clav.update(0,0,n-1,pos[b],c);
            continue;
        }
        swap(a,c);
        int res=0;
        b--;a--;
        for(;head[a]!=head[b];b=parent[head[b]]){
            if(depth[head[b]]<depth[head[a]])swap(a,b);
            res^=clav.query(0,0,n-1,pos[head[b]],pos[b]);
        }
        if(depth[b]<depth[a])swap(a,b);
        res^=clav.query(0,0,n-1,pos[a],pos[b]);
        cout << res << '\n';
    }
}