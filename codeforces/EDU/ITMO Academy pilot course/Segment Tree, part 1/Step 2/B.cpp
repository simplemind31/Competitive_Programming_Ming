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
        st[node]=st[hiji]+st[hijd];
        return;
    }
    void update(int node,int l,int r,int pos){
        if(l==r){
            st[node]=1-st[node];
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos);
        else update(hijd,mid+1,r,pos);
        st[node]=st[hiji]+st[hijd];
    }
    ll query(int node,int l,int r,int k){
        if(l==r)return l;
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(st[hiji]>k)return query(hiji,l,mid,k);
        else return query(hijd,mid+1,r,k-st[hiji]);
    }
    segment(vector<ll> x){
        a=x;
        tam=x.size();
        st.resize(4*tam+5);
        build(0,0,tam-1);
    }
};
int n,q,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    vector<ll> nums(n);
    for(int i=0;i<n;i++)cin >> nums[i];
    segment clav(nums);
    while(q--){
        cin >> a >> b;
        if(a==1)clav.update(0,0,n-1,b);
        else cout << clav.query(0,0,n-1,b) << '\n';
    }
}