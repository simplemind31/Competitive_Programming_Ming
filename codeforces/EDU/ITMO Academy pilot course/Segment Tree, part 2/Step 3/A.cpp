#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segment{
    int tam;
    vector<ll> a;
    vector<vector<ll>> st;
    // range,psum,ssum,sum
    void build(int node,int l,int r){
        if(l==r){
            st[node][0]=st[node][1]=st[node][2]=st[node][3]=a[l];
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node][0]=max({st[hiji][0],st[hijd][0],st[hiji][2]+st[hijd][1]});
        st[node][1]=max(st[hiji][1],st[hiji][3]+st[hijd][1]);
        st[node][2]=max(st[hijd][2],st[hijd][3]+st[hiji][2]);
        st[node][3]=st[hiji][3]+st[hijd][3];
        return;
    }
    void update(int node,int l,int r,int pos,int val){
        if(l==r){
            st[node][0]=st[node][1]=st[node][2]=st[node][3]=val;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
        st[node][0]=max({st[hiji][0],st[hijd][0],st[hiji][2]+st[hijd][1]});
        st[node][1]=max(st[hiji][1],st[hiji][3]+st[hijd][1]);
        st[node][2]=max(st[hijd][2],st[hijd][3]+st[hiji][2]);
        st[node][3]=st[hiji][3]+st[hijd][3];
    }
    vector<ll> query(int node,int l,int r,int i,int j){
        if(r<i || j<l)return {(ll)-1e18,(ll)-1e18,(ll)-1e18,(ll)-1e18};
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        vector<ll> iz=query(hiji,l,mid,i,j),de=query(hijd,mid+1,r,i,j),res(4);
        res[0]=max({iz[0],de[0],iz[2]+de[1]});
        res[1]=max(iz[1],iz[3]+de[1]);
        res[2]=max(de[2],de[3]+iz[2]);
        res[3]=iz[3]+de[3];
        return res;
    }
    segment(vector<ll> x){
        a=x;
        tam=x.size();
        st.assign(4*tam+5,vector<ll>(4));
        build(0,0,tam-1);
    }
};
int n,q,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    vector<ll> nums(n);
    for(int i=0;i<n;i++)cin >> nums[i];
    segment clav(nums);
    cout << ((clav.st[0][0]<0)?0:clav.st[0][0]) << '\n';
    while(q--){
        cin >> b >> c;
        clav.update(0,0,n-1,b,c);
        cout << ((clav.st[0][0]<0)?0:clav.st[0][0]) << '\n';
    }
}