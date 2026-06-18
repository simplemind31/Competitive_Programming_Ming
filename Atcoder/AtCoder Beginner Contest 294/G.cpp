#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,tiempo,q,a,b,c;
vector<pair<pair<ll,ll>,ll>> edges;
vector<vector<pair<ll,ll>>> graph;
vector<ll> tin,depth,tout;
vector<vector<ll>> parent;
vector<ll> dist;
void dfs(ll node){
    tin[node]=tiempo++;
    for(auto u:graph[node]){
        if(u.first==parent[node][0])continue;
        dist[u.first]=dist[node]+u.second;
        depth[u.first]=depth[node]+1;
        parent[u.first][0]=node;
        dfs(u.first);
    }
    tout[node]=tiempo-1;
}
struct segment{
    ll tam;
    vector<ll> a;
    vector<ll> st,lazy;
    void pushdown(ll node,ll l,ll r){
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(l!=r){
            lazy[hiji]+=lazy[node];
            lazy[hijd]+=lazy[node];
        }
        st[node]+=lazy[node];
        lazy[node]=0;
    }
    ll build(ll node,ll l,ll r){
        if(l==r)return st[node]=a[l];
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return st[node]=build(hiji,l,mid)+build(hijd,mid+1,r);
    }
    void update(ll node,ll l,ll r,ll i,ll j,ll val){
        pushdown(node,l,r);
        if(r<i || j<l)return;
        if(i<=l && r<=j){
            lazy[node]+=val;
            pushdown(node,l,r);
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        update(hiji,l,mid,i,j,val);
        update(hijd,mid+1,r,i,j,val);
        st[node]=st[hiji]+st[node];
    }
    ll query(ll node,ll l,ll r,ll i,ll j){
        pushdown(node,l,r);
        if(r<i || j<l)return 0;
        if(i<=l && r<=j)return st[node];
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return query(hiji,l,mid,i,j)+query(hijd,mid+1,r,i,j);
    }
    segment(vector<ll> x){
        tam=x.size();
        st.resize(4*tam);
        lazy.resize(4*tam);
        a=x;
        build(0,0,tam-1);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    edges.resize(n-1);
    graph.resize(n);
    tin.resize(n);
    tout.resize(n);
    depth.resize(n);
    parent.assign(n,vector<ll>(20));
    dist.resize(n);
    for(ll i=0;i<n-1;i++){
        cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
        graph[--edges[i].first.first].push_back({--edges[i].first.second,edges[i].second});
        graph[edges[i].first.second].push_back({edges[i].first.first,edges[i].second});
    }
    dfs(0);
    for(ll i=1;i<20;i++)for(ll j=0;j<n;j++)parent[j][i]=parent[parent[j][i-1]][i-1];
    vector<ll> base(n);
    for(ll i=0;i<n;i++)base[tin[i]]=dist[i];
    segment clav(base);
    cin >> q;
    while(q--){
        cin >> a >> b >> c;
        if(a==1){
            b--;
            ll u=edges[b].first.first,v=edges[b].first.second,dif=c-edges[b].second;
            edges[b].second=c;
            if(depth[u]>depth[v])swap(u,v);
            clav.update(0,0,n-1,tin[v],tout[v],dif);
            continue;
        }
        b--;c--;
        if(depth[b]>depth[c])swap(b,c);
        ll dista=clav.query(0,0,n-1,tin[b],tin[b])+clav.query(0,0,n-1,tin[c],tin[c]);
        for(ll i=19;i>=0;i--)if(depth[parent[c][i]]>=depth[b])c=parent[c][i];
        if(b==c){
            cout << dista-2*clav.query(0,0,n-1,tin[b],tin[b]) << '\n';
            continue;
        }
        for(ll i=19;i>=0;i--)if(parent[b][i]!=parent[c][i])b=parent[b][i],c=parent[c][i];
        b=parent[b][0];
        cout << dista-2*clav.query(0,0,n-1,tin[b],tin[b]) << '\n';
    }
}