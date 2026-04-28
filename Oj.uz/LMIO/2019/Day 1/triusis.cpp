#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,t,maxi=1;
struct segment{
    int tam;
    vector<int> st,a;
    void build(int node,int l,int r){
        if(l==r){
            st[node]=a[l];
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=max(st[hiji],st[hijd]);
    }
    int query(int node,int l,int r,int i,int j){
        if(r<i || j<l)return -1e9;
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return max(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    void update(int node,int l,int r,int pos,int val){
        if(l==r){
            st[node]=val;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
        st[node]=max(st[hiji],st[hijd]);
    }
    segment(vector<int> x){
        tam=x.size();
        a=x;
        st.resize(4*tam+5);
        build(0,0,tam-1);
    }
};
set<ll> diff;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> t;
    int nums[n+1],dp[n+1];// maximum number of unchanged si hasta i es unchanged
    fill(dp,dp+(n+1),-1e9);
    dp[0]=1;
    diff.insert(0-0*t);
    nums[0]=0;
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        diff.insert(1ll*nums[i]-1ll*i*t);
    }
    vector<ll> ord(ALL(diff));
    segment clav(vector<int> (ord.size(),-1e9));
    clav.update(0,0,ord.size()-1,lower_bound(ALL(ord),0)-ord.begin(),dp[0]);
    for(int i=1;i<=n;i++){
        // max(dp[j])+1 para todo nums[j]-j*t>=nums[i]-i*t 
        dp[i]=clav.query(0,0,ord.size()-1,lower_bound(ALL(ord),nums[i]-i*t)-ord.begin(),ord.size()-1)+1;
        clav.update(0,0,ord.size()-1,lower_bound(ALL(ord),nums[i]-i*t)-ord.begin(),dp[i]);
        maxi=max(maxi,dp[i]);
    }
    cout << n+1-maxi;
}