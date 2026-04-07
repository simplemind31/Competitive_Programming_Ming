#include <bits/stdc++.h>
#define LsOne(x) x&(-x)
using namespace std;
typedef long long ll;
const int MAXN=500000;
int n,m,q,a,tiempo,pad[MAXN],dist[MAXN],lo[MAXN],hi[MAXN];
pair<int,int> rango[MAXN];
ll target[MAXN];
vector<int> owns[MAXN],hij[MAXN];
pair<int,pair<ll,ll>> queries[MAXN];
vector<int> todo;
// sumar queries[i].second.first al rango del queries[i].first
    // para cada subnodoe c-> sumar (dist[c]-dist[queries[i].first])*queries[i].second.second
    // -> sumar -dist[queries[i].first]*queries[i].second.second+dist[c]*queries[i].second.second
    /*

    sumar queries[i].second.first-dist[queries[i].first]*queries[i].second.second a cada sub nodo, en seg1
    sumar queries[i].second.second para cada subnodo al seg 2
    res[c]=res[seg1]+dist[c]*res[seg2];
    */
pair<ll,ll> operator+(pair<ll,ll> a,pair<ll,ll> b){return {a.first+b.first,a.second+b.second};}
struct BIT{
    int tam;
    vector<pair<ll,ll>> fenwick;
    void update(int pos,pair<ll,ll> val){
        while(pos<tam+5){
            fenwick[pos]=fenwick[pos]+val;
            pos+=LsOne(pos);
        }
    }
    void update(int i,int j,pair<ll,ll> val){
        update(i+1,val);
        val.first*=-1;
        val.second*=-1;
        update(j+2,val);
    }
    pair<ll,ll> query(int pos){
        pair<ll,ll> res={0,0};
        pos++;
        while(pos>0){
            res=res+fenwick[pos];
            pos-=LsOne(pos);
        } 
        return res;
    }
    BIT(int x){
        tam=x;
        fenwick.resize(tam+5);
    }
};
struct segment{
    // range update poll query
    int tam;
    vector<pair<ll,ll>> st;
    void update(int node,int l,int r,int pos,pair<ll,ll>& val){
        st[node]=st[node]+val;
        if(l==r)return;
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
    }
    void update(int i,int j,pair<ll,ll> val){
        update(0,0,tam-1,i,val);
        val.first*=-1;
        val.second*=-1;
        update(0,0,tam-1,j+1,val);
    }
    pair<ll,ll> query(int node,int l,int r,int i,int j){
        if(r<i || j<l)return {0,0};
        if(i<=l && r<=j)return st[node];
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        return query(hiji,l,mid,i,j)+query(hijd,mid+1,r,i,j);
    }
    pair<ll,ll> query(int pos){return query(0,0,tam-1,0,pos);}
    segment(int x){
        tam=x;
        st.resize(4*tam+5);
    }
};
BIT clav(1);
void solve(int l,int r,vector<int>& canditate){
    if(l==r){
        for(auto u:canditate)lo[u]=l;
        return;
    }
    int mid=(l+r)>>1;
    for(int i=l;i<=mid;i++){
        clav.update(rango[queries[i].first].first,rango[queries[i].first].second,{queries[i].second.first-dist[queries[i].first]*queries[i].second.second,queries[i].second.second});
    }
    vector<int> iz,de;
    for(auto u:canditate){
        ll suma=0;
        for(auto v:owns[u]){
            pair<ll,ll> res=clav.query(rango[v].first);
            suma+=res.first+dist[v]*res.second;
        }
        if(suma>=target[u])iz.push_back(u);
        else{
            target[u]-=suma;
            de.push_back(u);
        }
    }
    for(int i=l;i<=mid;i++){
        clav.update(rango[queries[i].first].first,rango[queries[i].first].second,{-(queries[i].second.first-dist[queries[i].first]*queries[i].second.second),-(queries[i].second.second)});
    }
    solve(l,mid,iz);
    solve(mid+1,r,de);
}
void dfs(int node){
    rango[node].first=tiempo++;
    for(auto u:hij[node])dfs(u);
    rango[node].second=tiempo-1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<n;i++){
        cin >> pad[i];
        dist[i]=dist[--pad[i]]+1;
        hij[pad[i]].push_back(i);
    }
    for(int i=0;i<n;i++){
        cin >> a;
        owns[--a].push_back(i);
    }
    for(int i=0;i<m;i++){
        cin >> target[i];
        todo.push_back(i);
    }
    cin >> q;
    for(int i=0;i<m;i++)hi[i]=q;
    for(int i=0;i<q;i++){
        cin >> queries[i].first >> queries[i].second.first >> queries[i].second.second;
        queries[i].first--;
    }
    dfs(0);
    clav=BIT(tiempo+1);
    solve(0,q,todo);
    /*while(true){
        vector<vector<int>> bucket(q+1);
        bool changed=false;
        for(int i=0;i<m;i++){
            if(lo[i]<hi[i]){
                changed=true;
                bucket[(lo[i]+hi[i])>>1].push_back(i);
            }
        }
        if(!changed)break;
        BIT clav(tiempo+1);
        for(int i=0;i<q;i++){
            clav.update(rango[queries[i].first].first,rango[queries[i].first].second,{queries[i].second.first-dist[queries[i].first]*queries[i].second.second,queries[i].second.second});
            for(auto u:bucket[i]){
                ll suma=0;
                for(auto v:owns[u]){
                    pair<ll,ll> res=clav.query(rango[v].first);
                    suma+=res.first+dist[v]*res.second;
                }
                if(suma>=target[u])hi[u]=i;
                else lo[u]=i+1;
            }
        }
    }*/
    for(int i=0;i<m;i++){
        if(lo[i]==q)cout << "rekt\n";
        else cout << lo[i]+1 << '\n';
    }
}