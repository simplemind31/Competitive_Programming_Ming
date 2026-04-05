#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segment{
    int tam;
    vector<ll> st;
    void build(int node,int l,int r){
        if(l==r){
            st[node]=0;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=st[hiji]+st[hijd];
        return;
    }
    void update(int node,int l,int r,int pos,int val){
        if(l==r){
            st[node]+=val;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
        st[node]=st[hiji]+st[hijd];
    }
    ll query(int node,int l,int r,int i,int j){
        if(r<i || j<l)return 0;
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return query(hiji,l,mid,i,j)+query(hijd,mid+1,r,i,j);
    }
    segment(int x){
        tam=x;
        st.resize(4*tam+5);
        //build(0,0,tam-1);
    }
};
int n,q,a,b,c,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    segment clav(n+1);
    while(q--){
        cin >> a;
        if(a==1){
            cin >> b >> c >> d;
            clav.update(0,0,n,b,d);
            clav.update(0,0,n,c,-d);
        }else{
            cin >> b;
            cout << clav.query(0,0,n,0,b) << '\n';
        }
    }
}