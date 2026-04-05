#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segment{
    int tam;
    vector<int> st;
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
    for(int i=0;i<n;i++){
        cout << clav.query(0,0,n-1,nums[i]-1,n-1) << ' ';
        clav.update(0,0,n-1,nums[i]-1,1);
    }
}