#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segment{
    int tam;
    vector<int> a,st;
    // todos los de l a r son i y el minimo es j
    void build(int node,int l,int r){
        if(l==r){
            st[node]=a[l];
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=min(st[hiji],st[hijd]);
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
        st[node]=min(st[hiji],st[hijd]);
    }
    int query(int node,int l,int r,int i,int j,int power){
        if(r<i || j<l || st[node]>power)return 0;
        if(l==r){
            st[node]=1e9+7;
            return 1;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        int a=query(hiji,l,mid,i,j,power),b=query(hijd,mid+1,r,i,j,power);
        st[node]=min(st[hiji],st[hijd]);
        return a+b;
    }
    segment(int x){
        tam=x;
        st.assign(4*tam+5,1e9+7);
        //build(0,0,tam-1);
    }
};
int n,q,a,b,c,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    segment clav(n);
    while(q--){
        cin >> a >> b >> c;
        if(a==1)clav.update(0,0,n-1,b,c);
        else{
            cin >> d;
            cout << clav.query(0,0,n-1,b,c-1,d) << '\n';
        }
    }
    //cout << "a";
}