#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int r;
struct segment{
    int tam;
    vector<int> a,neutro;
    vector<vector<int>> st;
    vector<int> merge(vector<int> a,vector<int> b){
        vector<int> c(41);
        for(int i=0;i<40;i++)c[40]+=((c[i]=a[i]+b[i])>0);
        return c;
    }
    void build(int node,int l,int r){
        if(l==r){
            st[node][a[l]-1]=1;
            st[node][40]=1;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=merge(st[hiji],st[hijd]);
        return;
    }
    void update(int node,int l,int r,int pos,int val){
        st[node][40]-=(--st[node][a[pos]-1]==0);
        st[node][40]+=(st[node][val-1]++==0);
        if(l==r){
            a[pos]=val;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
    }
    vector<int> query(int node,int l,int r,int i,int j){
        if(r<i || j<l)return neutro;
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return merge(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    segment(vector<int> x){
        a=x;
        tam=x.size();
        st.assign(4*tam+5,vector<int>(41));
        neutro.resize(41);
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