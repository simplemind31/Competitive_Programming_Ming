#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segment{
    int tam;
    vector<int> st,lazy;
    void push_down(int node,int l,int r){
        int hiji=2*node+1,hijd=2*node+2;
        if(l!=r){
            lazy[hiji]=max(lazy[node],lazy[hiji]);
            lazy[hijd]=max(lazy[node],lazy[hijd]);
        }
        st[node]=max(lazy[node],st[node]);
        lazy[node]=0;
    }
    void update(int node,int l,int r,int i,int j,int val){
        push_down(node,l,r);
        if(r<i || j<l)return;
        if(i<=l && r<=j){
            lazy[node]=max(val,lazy[node]);
            push_down(node,l,r);
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        update(hiji,l,mid,i,j,val);
        update(hijd,mid+1,r,i,j,val);
        st[node]=max(st[hiji],st[hijd]);
    }
    int query(int node,int l,int r,int i,int j){
        push_down(node,l,r);
        if(r<i || j<l)return 0;
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return max(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    segment(int n){
        tam=n;
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
        cin >> a >> b;
        if(a==1){
            cin >> c >> d;
            clav.update(0,0,n-1,b,c-1,d);
        }else{
            cout << clav.query(0,0,n-1,b,b) << '\n';
        }
    }
}