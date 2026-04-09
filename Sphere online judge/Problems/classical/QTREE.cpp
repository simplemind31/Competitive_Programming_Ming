#include <bits/stdc++.h>
using namespace std;
struct segment{
    int tam;
    vector<int> a,st;
    void build(int node,int l,int r){
        if(l==r){
            st[node]=a[l];
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=max(st[hiji],st[hijd]);
    }
    void update(int node,int l,int r,int pos,int val){
        if(l==r){
            st[node]=val;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
        st[node]=max(st[hiji],st[hijd]);
    }
    int query(int node,int l,int r,int i,int j){
        if(r<i || j<l)return -1e9;
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return max(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    segment(vector<int> x){
        tam=x.size();
        a=x;
        st.resize(4*tam+5);
        build(0,0,tam-1);
    }
};
int tiempo;
vector<int> val,bigchild,head,pos,depth,parent;
vector<pair<pair<int,int>,int>> edge;
vector<vector<pair<int,int>>> graph;
int t,n,a,b;
int dfs(int node){
    int tam=1,tambig=0;
    bigchild[node]=-1;
    for(auto u:graph[node]){
        if(u.first==parent[node])continue;
        val[u.first]=u.second;
        parent[u.first]=node;
        depth[u.first]=depth[node]+1;
        int tamu=dfs(u.first);
        if(tamu>tambig){
            tambig=tamu;
            bigchild[node]=u.first;
        }
        tam+=tamu;
    }
    return tam;
}
void descompose(int node,int h){
    head[node]=h;
    pos[node]=tiempo++;
    if(bigchild[node]!=-1){
        descompose(bigchild[node],h);
    }
    for(auto u:graph[node]){
        if(u.first==parent[node] || u.first==bigchild[node])continue;
        descompose(u.first,u.first);
    }
}
string tipo;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        tiempo=0;
        val.clear();
        parent.clear();
        depth.clear();
        graph.clear();
        edge.clear();
        bigchild.clear();
        head.clear();
        pos.clear();
        cin >> n;
        val.resize(n);
        graph.resize(n);
        parent.resize(n);
        depth.resize(n);
        edge.resize(n-1);
        bigchild.resize(n);
        pos.resize(n);
        head.resize(n);
        val[0]=-1e9;
        parent[0]=-1;
        depth[0]=0;
        for(int i=0;i<n-1;i++){
            cin >> edge[i].first.first >> edge[i].first.second >> edge[i].second;
            graph[--edge[i].first.first].push_back({--edge[i].first.second,edge[i].second});
            graph[edge[i].first.second].push_back({edge[i].first.first,edge[i].second});
        }
        dfs(0);
        descompose(0,0);
        for(int i=0;i<n-1;i++){
            if(depth[edge[i].first.first]>depth[edge[i].first.second])swap(edge[i].first.first,edge[i].first.second);
        }
        vector<int> base(n);
        for(int i=0;i<n;i++){
            base[pos[i]]=val[i];
        }
        segment clav(base);
        while(1){
            cin >> tipo;
            if(tipo=="DONE")break;
            cin >> a >> b;
            if(tipo=="CHANGE"){
                a--;
                clav.update(0,0,n-1,pos[edge[a].first.second],b);
            }else{
                a--;
                b--;
                int res=0;
                for(;head[a]!=head[b];b=parent[head[b]]){
                    if(depth[head[a]]>depth[head[b]])swap(a,b);
                    int temp=clav.query(0,0,n-1,pos[head[b]],pos[b]);
                    res=max(res,temp);
                }
                if(depth[a]>depth[b])swap(a,b);
                if(a!=b){
                    int temp=clav.query(0,0,n-1,pos[a]+1,pos[b]);
                    res=max(res,temp);
                }
                cout << res << '\n';
            }
        }
    }
}