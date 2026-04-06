#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segment{
    int tam;
    vector<int> a;
    // weight sum, normal sum, length
    vector<pair<pair<ll,ll>,ll>> st;
    vector<ll> lazy;
    void push_down(int node,int l,int r){
        if(!lazy[node])return;
        int hiji=2*node+1,hijd=2*node+2;
        if(l!=r){
            lazy[hiji]+=lazy[node];
            lazy[hijd]+=lazy[node];
        }
        ll lon=r-l+1;
        st[node].first.first+=lon*(lon+1)/2*lazy[node];
        st[node].first.second+=lon*lazy[node];
        lazy[node]=0;
    }
    pair<pair<ll,ll>,ll> merge(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b){
        pair<pair<ll,ll>,ll> c;
        c.first.second=a.first.second+b.first.second;
        c.second=a.second+b.second;
        c.first.first=a.first.first+b.first.first+a.second*b.first.second;
        return c;
    }
    void build(int node,int l,int r){
        if(l==r){
            st[node]={{a[l],a[l]},1};
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=merge(st[hiji],st[hijd]);
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
        st[node]=merge(st[hiji],st[hijd]);
    }
    pair<pair<ll,ll>,ll> query(int node,int l,int r,int i,int j){
        push_down(node,l,r);
        if(r<i || j<l)return {{0,0},0};
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return merge(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    segment(vector<int> x){
        a=x;
        tam=x.size();
        st.resize(4*tam+5);
        lazy.resize(4*tam+5);
        build(0,0,tam-1);
    }
};
int n,q,a,b,c,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin >> nums[i];
    segment clav(nums);
    // 1=black 0white
    while(q--){
        cin >> a >> b >> c;
        if(a==1){
            cin >> d;
            clav.update(0,0,n-1,b-1,c-1,d);
        }else cout << clav.query(0,0,n-1,b-1,c-1).first.first << '\n';
    }
}