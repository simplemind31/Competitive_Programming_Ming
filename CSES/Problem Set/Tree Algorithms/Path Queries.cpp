#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segment{
    ll tam;
    vector<ll> st,a;
    void build(ll node,ll l,ll r){
        if(l==r){
            st[node]=a[l];
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=st[hiji]+st[hijd];
    }
    void update(ll node,ll l,ll r,ll pos,ll val){
        if(l==r){
            st[node]=val;
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
        st[node]=st[hiji]+st[hijd];
    }
    ll query(ll node,ll l,ll r,ll i,ll j){
        if(r<i || j<l)return 0;
        if(i<=l && r<=j)return st[node];
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return query(hiji,l,mid,i,j)+query(hijd,mid+1,r,i,j);
    }
    segment(vector<ll> nums){
        a=nums;
        tam=nums.size();
        st.resize(4*tam+5);
        build(0,0,tam-1);
    }
};
ll n,q,a,b,c,tiempo;
vector<ll> val,head,pos,parent,bigchild,depth;
vector<vector<ll>> graph;
ll dfs(ll node){
    ll tam=1,tambig=0;
    bigchild[node]=-1;
    for(auto u:graph[node]){
        if(u==parent[node])continue;
        depth[u]=depth[node]+1;
        parent[u]=node;
        ll tamu=dfs(u);
        if(tamu>tambig){
            tambig=tamu;
            bigchild[node]=u;
        }
        tam+=tamu;
    }
    return tam;
}
void descompose(ll node,ll h){
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
    for(ll i=0;i<n;i++){
        cin >> val[i];
    }
    for(ll i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0);
    descompose(0,0);
    vector<ll> base(n);
    for(ll i=0;i<n;i++){
        base[pos[i]]=val[i];
    }
    segment clav(base);
    while(q--){
        cin >> a >> b;
        if(a==1){
            cin >> c;
            b--;
            // update
            clav.update(0,0,n-1,pos[b],c);
            continue;
        }else{
            ll res=0;
            b--;
            a=0;
            for(;head[a]!=head[b];b=parent[head[b]]){
                if(depth[head[b]]<depth[head[a]])swap(a,b);
                res+=clav.query(0,0,n-1,pos[head[b]],pos[b]);
            }
            if(depth[b]<depth[a])swap(a,b);
            res+=clav.query(0,0,n-1,pos[a],pos[b]);
            cout << res << '\n';
        }
    }
}