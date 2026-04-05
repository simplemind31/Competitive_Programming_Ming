#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int r;
vector<ll> nada(41);
struct segment{
    int tam;
    vector<int> a;
    vector<vector<ll>> st;
    vector<ll> merge(vector<ll> a,vector<ll> b){
        vector<ll> c(41);
        for(int i=0;i<=40;i++){
            c[i]=a[i]+b[i];
        }
        for(int i=38;i>=0;i--)a[i]+=a[i+1];
        for(int i=0;i<=38;i++)c[40]+=a[i+1]*b[i];
        return c;
    }
    void build(int node,int l,int r){
        if(l==r){
            st[node][a[l]-1]++;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=merge(st[hiji],st[hijd]);
        return;
    }
    void update(int node,int l,int r,int pos,int val){
        if(l==r){
            st[node][a[l]-1]--;
            a[l]=val;
            st[node][a[l]-1]++;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
        st[node]=merge(st[hiji],st[hijd]);
    }
    vector<ll> query(int node,int l,int r,int i,int j){
        if(r<i || j<l)return nada;
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return merge(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    segment(vector<int> x){
        a=x;
        tam=x.size();
        st.assign(4*tam+5,vector<ll>(41));
        build(0,0,tam-1);
    }
};
int n,q,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin >> nums[i];
    segment clav(nums);
    while(q--){
        cin >> a >> b >> c;
        if(a==1)cout << clav.query(0,0,n-1,b-1,c-1)[40] << '\n';
        else clav.update(0,0,n-1,b-1,c);
    }
}