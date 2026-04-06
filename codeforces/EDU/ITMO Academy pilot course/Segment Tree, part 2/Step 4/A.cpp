#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segment{
    int tam;
    vector<ll> st;
    vector<pair<bool,ll>> lazy;
    // true= assign
    void apply(int node,pair<bool,ll> op){
        if(op.first)lazy[node]=op;
        else lazy[node].second+=op.second;
    }
    void push_down(int node,int l,int r){
        int hiji=2*node+1,hijd=2*node+2;
        if(l!=r){
            apply(hiji,lazy[node]);
            apply(hijd,lazy[node]);
        }
        if(lazy[node].first)st[node]=lazy[node].second*(r-l+1);
        else st[node]+=lazy[node].second*(r-l+1);
        lazy[node]={0,0};
    }
    void update(int node,int l,int r,int i,int j,pair<bool,ll> val){
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
        st[node]=st[hiji]+st[hijd];
    }
    ll query(int node,int l,int r,int i,int j){
        push_down(node,l,r);
        if(r<i || j<l)return 0;
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return query(hiji,l,mid,i,j)+query(hijd,mid+1,r,i,j);
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
        cin >> a >> b >> c;
        if(a!=3){
            cin >> d;
            if(a==1)clav.update(0,0,n-1,b,c-1,{1,d});
            else clav.update(0,0,n-1,b,c-1,{0,d});
        }else{
            cout << clav.query(0,0,n-1,b,c-1) << '\n';
        }
    }
}