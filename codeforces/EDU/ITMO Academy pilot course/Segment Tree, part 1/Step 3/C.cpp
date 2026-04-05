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
            st[node]=val;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
        st[node]=st[hiji]+st[hijd];
    }
    int query(int node,int l,int r,int i,int j){
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
int n,q,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> nums(2*n),res(n);
    vector<pair<int,int>> pos(n,{-1,-1});
    for(int i=0;i<2*n;i++){
        cin >> nums[i];
        if(pos[--nums[i]].first==-1)pos[nums[i]].first=i;
        else pos[nums[i]].second=i;
    }
    segment clav(2*n);
    for(int i=0;i<2*n;i++){
        if(i==pos[nums[i]].second){
            res[nums[i]]=clav.query(0,0,2*n-1,pos[nums[i]].first,pos[nums[i]].second);
            clav.update(0,0,2*n-1,pos[nums[i]].first,1);
        }
    }
    for(int i=0;i<n;i++)cout << res[i] << ' ';
}