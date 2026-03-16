#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,x;
struct segmenttree{
    vector<ll> st;
    void update(int node,int l,int r,int pos,ll val){
        if(l==r){
            st[node]=val;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
        st[node]=max(st[hiji],st[hijd]);
    }
    ll query(int node,int l,int r,int i,int j){
        if(r<i ||j<l)return 0;
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return max(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    segmenttree(int n){
        st.resize(4*n+5);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int h[n];
    for(int i=0;i<n;i++)cin >> h[i];
    segmenttree clave(n);
    for(int i=0;i<n;i++){
        cin >> x;
        clave.update(0,0,n,h[i],clave.query(0,0,n,0,h[i])+x);
    }
    cout << clave.query(0,0,n,0,n);
}