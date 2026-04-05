#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segment{
    int tam;
    vector<ll> st,a;
    void build(int node,int l,int r){
        if(l==r){
            st[node]=a[l];
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=max(st[hiji],st[hijd]);
        return;
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
    ll query(int node,int l,int r,int k,int mini){
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
        lazy.
    }
};
int n,q,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    segment clav(n);
    while(q--){
        cin >> a >> b >> c;
        if(a==1)clav.update(0,0,n-1,b,c);
        else{
            cout << clav.query(0,0,n-1,b,c) << '\n';
        }
    }
}