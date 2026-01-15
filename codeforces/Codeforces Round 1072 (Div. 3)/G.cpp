#include <bits/stdc++.h>
using namespace std;
int t,n,q,c,a,b;
struct Segment{
    int tam;
    vector<int> a,st;
    void build(int node,int l,int r){
        if(l==r){
            st[node]=a[l];
            return;
        }
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=min(st[hiji],st[hijd]);
    }
    void update(int node,int l,int r,int pos,int val){
        if(l==r){
            st[node]=val;
            return;
        }
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
        st[node]=min(st[hiji],st[hijd]);
    }
    int query(int node,int l,int r,int i,int j){
        if(r<i || j<l)return 1e9;
        if(i<=l && r<=j)return st[node];
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        return min(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    Segment(vector<int> x){
        tam=(a=x).size();
        st.resize(4*tam);
        build(0,0,tam-1);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> q;
        vector<int> nums(n);
        for(int i=0;i<n;i++)cin >> nums[i];
        Segment clav(nums);
        while(q--){
            cin >> c >> a >> b;
            if(c==1){
                clav.update(0,0,n-1,a-1,b);
                continue;
            }
            int l=0,r=(--b)-(--a);
            while(l<r){
                int mid=(l+r+1)>>1;
                if(clav.query(0,0,n-1,a,a+mid)<mid)r=mid-1;
                else l=mid;
            }
            if(clav.query(0,0,n-1,a,a+l)==l)cout << "1\n";
            else cout << "0\n";
        }
    }
}