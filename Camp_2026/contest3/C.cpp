#include <bits/stdc++.h>
using namespace std;
int now,tiempo,n,m,q,a,b,pad[500000],tam[500000],val[500000],ver[500000],alt[500000],bj[500000][20];
vector<int> graph[500000],tin;
int find(int x){return (pad[x]==x)?x:(pad[x]=find(pad[x]));}
bool unite(int x,int y,int ind){
    if((x=find(x))==(y=find(y)))return false;
    pad[x]=now;
    pad[y]=now;
    graph[x].push_back(now);
    graph[y].push_back(now);
    graph[now].push_back(x);
    graph[now].push_back(y);
    val[now]=ind;
    now++;
    return true;
}
void dfs(int node,int ante){
    tin[node]=tiempo;
    ver[tiempo++]=node;
    for(auto u:graph[node]){
        if(u==ante)continue;
        alt[u]=alt[node]+1;
        bj[u][0]=node;
        dfs(u,node);
    }
}
struct segment{
    int tam;
    vector<int> a;
    vector<pair<int,int>> st;
    void build(int node,int l,int r){
        if(l==r){
            st[node]={a[l],a[l]};
            return;
        }
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]={min(st[hiji].first,st[hijd].first),max(st[hiji].second,st[hijd].second)};
    }
    pair<int,int> query(int node,int l,int r,int i,int j){
        if(r<i || j<l)return {1e9,-1};
        if(i<=l && r<=j)return st[node];
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        pair<int,int> iz=query(hiji,l,mid,i,j),de=query(hijd,mid+1,r,i,j);
        return {min(iz.first,de.first),max(iz.second,de.second)};
    }
    segment(vector<int> x){
        a=x;
        tam=x.size();
        st.resize(4*tam+5);
        build(0,0,tam-1);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    tin.resize(2*n-1);
    now=n;
    for(int i=0;i<2*n;i++)tam[pad[i]=i]=1;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        unite(a,b,i);
    }
    // root es 2*n-2
    bj[2*n-2][0]=2*n-2;
    dfs(2*n-2,-1);
    for(int i=1;i<20;i++){
        for(int j=0;j<2*n;j++){
            bj[j][i]=bj[bj[j][i-1]][i-1];
        }
    }
    segment clav(tin);
    while(q--){
        cin >> a >> b;
        pair<int,int> temp=clav.query(0,0,2*n-2,a,b);
        a=ver[temp.first];
        b=ver[temp.second];
        // lca de a,b
        if(alt[a]>alt[b])swap(a,b);
        int dist=alt[b]-alt[a];
        for(int i=19;i>=0;i--){
            if(dist&(1<<i))b=bj[b][i];
        }
        for(int i=19;i>=0;i--){
            if(bj[a][i]!=bj[b][i]){
                a=bj[a][i];
                b=bj[b][i];
            }
        }
        a=bj[a][0];
        cout << val[a]+1 << '\n';
    }
    //cout << 'a';
}