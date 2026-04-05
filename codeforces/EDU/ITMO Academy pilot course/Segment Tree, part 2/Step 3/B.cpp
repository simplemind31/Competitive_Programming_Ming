#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segment{
    int tam;
    vector<ll> st;
    vector<bool> lazy;
    void push_down(int node,int l,int r){
        if(!lazy[node])return;
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(l!=r){
            lazy[hiji]=lazy[hiji]^lazy[node];
            lazy[hijd]=lazy[hijd]^lazy[node];
        }
        st[node]=r-l+1-st[node];
        lazy[node]=0;
    }
    void update(int node,int l,int r,int i,int j){
        push_down(node,l,r);
        if(r<i || j<l)return;
        if(i<=l && r<=j){
            lazy[node]=lazy[node]^1;
            push_down(node,l,r);
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        update(hiji,l,mid,i,j);
        update(hijd,mid+1,r,i,j);
        st[node]=st[hiji]+st[hijd];
    }
    ll query(int node,int l,int r,int k){
        push_down(node,l,r);
        if(l==r)return l;
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        push_down(hiji,l,mid);
        if(st[hiji]>k)return query(hiji,l,mid,k);
        else return query(hijd,mid+1,r,k-st[hiji]);
    }
    segment(int x){
        tam=x;
        st.resize(4*tam+5);
        lazy.resize(4*tam+5);
    }
};
int n,q,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    segment clav(n);
    while(q--){
        cin >> a >> b;
        if(a==1){
            cin >> c;
            clav.update(0,0,n-1,b,c-1);
        }else cout << clav.query(0,0,n-1,b) << '\n';
    }
}