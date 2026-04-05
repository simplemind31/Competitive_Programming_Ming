#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segment{
    int tam;
    vector<ll> st;
    void build(int node,int l,int r){
        if(l==r){
            st[node]=1;
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
    ll query(int node,int l,int r,int k){
        if(l==r)return l;
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(st[hijd]>=k)return query(hijd,mid+1,r,k);
        else return query(hiji,l,mid,k-st[hijd]);
    }
    segment(int x){
        tam=x;
        st.resize(4*tam+5);
        build(0,0,tam-1);
    }
};
int n,q,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<ll> nums(n);
    for(int i=0;i<n;i++)cin >> nums[i];
    segment clav(n);
    for(int i=n-1;i>=0;i--){
        // hay nums[i] mayores que yo, sin contar los que estan a la derecha
        // inicialmente todo es 1, entontrar el nums[i]+1 uno desde derecha
        nums[i]=clav.query(0,0,n-1,nums[i]+1);
        clav.update(0,0,n-1,nums[i],0);
    }
    for(int i=0;i<n;i++)cout << nums[i]+1 << ' ';
}