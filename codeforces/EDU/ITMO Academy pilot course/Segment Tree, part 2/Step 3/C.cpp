#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segment{
    int tam;
    vector<ll> st,lazy;
    // max
    void push_down(int node,int l,int r){
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(l!=r){
            lazy[hiji]+=lazy[node];
            lazy[hijd]+=lazy[node];
        }
        st[node]+=lazy[node];
        lazy[node]=0;
    }
    void update(int node,int l,int r,int i,int j,int val){
        push_down(node,l,r);
        if(r<i || j<l)return;
        if(i<=l && r<=j){
            lazy[node]+=val;
            push_down(node,l,r);
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        update(hiji,l,mid,i,j,val);
        update(hijd,mid+1,r,i,j,val);
        st[node]=max(st[hiji],st[hijd]);
    }
    ll query(int node,int l,int r,int k,int mini){
        push_down(node,l,r);
        if(r<mini || st[node]<k)return -1;
        if(l==r)return l;
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        int res=query(hiji,l,mid,k,mini);
        if(res==-1)res=query(hijd,mid+1,r,k,mini);
        return res;
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
        if(a==1){
            cin >> d;
            clav.update(0,0,n-1,b,c-1,d);
        }else cout << clav.query(0,0,n-1,b,c) << '\n';
    }
}