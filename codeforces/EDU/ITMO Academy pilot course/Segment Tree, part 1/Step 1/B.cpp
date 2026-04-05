#include <bits/stdc++.h>
using namespace std;
struct segment{
    int tam;
    vector<int> a;
    vector<pair<int,int>> st;
    void build(int node,int l,int r){
        if(l==r){
            st[node]={a[l],1};
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        if(st[hiji].first<st[hijd].first)st[node]=st[hiji];
        else if(st[hiji].first>st[hijd].first)st[node]=st[hijd];
        else st[node]={st[hiji].first,st[hijd].second+st[hiji].second};
        return;
    }
    void update(int node,int l,int r,int pos,int val){
        if(l==r){
            st[node].first=val;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
        if(st[hiji].first<st[hijd].first)st[node]=st[hiji];
        else if(st[hiji].first>st[hijd].first)st[node]=st[hijd];
        else st[node]={st[hiji].first,st[hijd].second+st[hiji].second};
        return;
    }
    pair<int,int> query(int node,int l,int r,int i,int j){
        if(r<i || j<l)return {1e9,0};
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        pair<int,int> iz=query(hiji,l,mid,i,j),de=query(hijd,mid+1,r,i,j);
        if(iz.first<de.first)return iz;
        else if(iz.first>de.first)return de;
        else return {iz.first,iz.second+de.second};
    }
    segment(vector<int> x){
        a=x;
        tam=x.size();
        st.resize(4*tam+5);
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
        if(a==1)clav.update(0,0,n-1,b,c);
        else cout << clav.query(0,0,n-1,b,c-1).first << '\n';
    }
}