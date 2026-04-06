#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segment{
    int tam;
    // min max
    // incrementar, decrementar
    vector<pair<int,int>> st;
    vector<pair<int,int>> lazy;
    // first<=second siempre
    void apply(int node,pair<int,int> op){
        if(op.first>=lazy[node].second){
            // incre
            lazy[node]={op.first,op.first};
        }else if(op.second<=lazy[node].first){
            // decre
            lazy[node]={op.second,op.second};
        }else{
            lazy[node].first=max(lazy[node].first,op.first);
            lazy[node].second=min(lazy[node].second,op.second);
        }
    }
    void push_down(int node,int l,int r){
        int hiji=2*node+1,hijd=2*node+2;
        if(l!=r){
            apply(hiji,lazy[node]);
            apply(hijd,lazy[node]);
        }
        if(lazy[node].first>=st[node].second)st[node]={lazy[node].first,lazy[node].first};
        else if(lazy[node].second<=st[node].first)st[node]={lazy[node].second,lazy[node].second};
        else{
            st[node].first=max(st[node].first,lazy[node].first);
            st[node].second=min(st[node].second,lazy[node].second);
        }
        lazy[node]={0,1e9};
    }
    pair<int,int> merge(pair<int,int> a,pair<int,int> b){
        pair<int,int> c;
        c.first=min(a.first,b.first);
        c.second=max(a.second,b.second);
        return c;
    }
    void update(int node,int l,int r,int i,int j,pair<int,int> val){
        push_down(node,l,r);
        if(r<i || j<l)return;
        if(i<=l && r<=j){
            apply(node,val);
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
        if(r<i || j<l)return {1e9,0};
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return merge(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    segment(int x){
        tam=x;
        st.resize(4*tam+5);
        lazy.resize(4*tam+5);
    }
};
int n,q,a,b,c,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    segment clav(n);
    while(q--){
        cin >> a >> b >> c >> d;
        if(a==1){
            clav.update(0,0,n-1,b,c,{d,1e9});
            // add todo de b,c hasta d
            // el min es d
        }
        else{
            clav.update(0,0,n-1,b,c,{0,d});
            // quitar todo hasta d;
            // el max es d
        }
    }
    for(int i=0;i<n;i++){
        cout << clav.query(0,0,n-1,i,i).second << '\n';
    }
}