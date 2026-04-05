#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//3 3 -1 -1 3
struct segment{
    int tam;
    vector<ll> lazy;
    vector<vector<ll>> st;
    // range,psum,ssum,sum
    void push_down(int node,int l,int r){
        if(lazy[node]==1e18)return;
        int hiji=2*node+1,hijd=2*node+2;
        if(l!=r){
            lazy[hiji]=lazy[node];
            lazy[hijd]=lazy[node];
        }
        ll val=max((r-l+1)*lazy[node],0ll);
        st[node]={val,val,val,(r-l+1)*lazy[node]};
        lazy[node]=1e18;
    }
    void update(int node,int l,int r,int i,int j,int val){
        push_down(node,l,r);
        if(r<i || j<l)return;
        if(i<=l && r<=j){
            lazy[node]=val;
            push_down(node,l,r);
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        update(hiji,l,mid,i,j,val);
        update(hijd,mid+1,r,i,j,val);
        st[node][0]=max({st[hiji][0],st[hijd][0],st[hiji][2]+st[hijd][1]});
        st[node][1]=max(st[hiji][1],st[hiji][3]+st[hijd][1]);
        st[node][2]=max(st[hijd][2],st[hijd][3]+st[hiji][2]);
        st[node][3]=st[hiji][3]+st[hijd][3];
    }
    vector<ll> query(int node,int l,int r,int i,int j){
        push_down(node,l,r);
        if(r<i || j<l)return {0,0,0,0};
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        vector<ll> iz=query(hiji,l,mid,i,j),de=query(hijd,mid+1,r,i,j),res(4);
        res[0]=max({iz[0],de[0],iz[2]+de[1]});
        res[1]=max(iz[1],iz[3]+de[1]);
        res[2]=max(de[2],de[3]+iz[2]);
        res[3]=iz[3]+de[3];
        return res;
    }
    segment(int x){
        tam=x;
        st.assign(4*tam+5,vector<ll>(4));
        lazy.resize(4*tam+5,1e18);
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
        clav.update(0,0,n-1,a,b-1,c);
        clav.push_down(0,0,n-1);
        cout << clav.st[0][0] << '\n';
    }
}