#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll t,n;
struct segment{
    ll tam;
    vector<ll> a,st;
    void build(ll node,ll l,ll r){
        if(l==r){
            st[node]=a[l];
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=max(st[hiji],st[hijd]);
    }
    ll query(ll node,ll l,ll r,ll i,ll j){
        if(r<i || j<l)return 0;
        if(i<=l && r<=j)return st[node];
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return max(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    void update(ll node,ll l,ll r,ll pos,ll val){
        if(l==r){
            st[node]=val;
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
        st[node]=max(st[hiji],st[hijd]);
    }
    segment(vector<ll> x){
        tam=x.size();
        a=x;
        st.resize(4*tam+5);
        build(0,0,tam-1);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<ll> nums(n),maxi(n),pos(n);
        pos[0]=0;
        for(ll i=0;i<n;i++){
            cin >> nums[i];
        }
        for(ll i=1;i<n;i++){
            cin >> pos[i];
            pos[i]+=pos[i-1];
        }
        segment clav(maxi);
        maxi[n-1]=n-1;
        clav.update(0,0,n-1,n-1,maxi[n-1]);
        for(ll i=n-2;i>=0;i--){
            // [pos[i],pos[i]+nums[i])
            ll r=lower_bound(ALL(pos),pos[i]+nums[i])-pos.begin()-1;
            maxi[i]=clav.query(0,0,n-1,i,r);
            clav.update(0,0,n-1,i,maxi[i]);
        }
        if(maxi[0]==n-1){
            cout << "habibi\n";
            continue;
        }
        for(ll i=0;i<n;i++){
            pos[i]=pos[n-1]-pos[i];
        }
        reverse(ALL(pos));
        reverse(ALL(nums));
        maxi.assign(n,0);
        clav=segment(maxi);
        maxi[n-1]=n-1;
        clav.update(0,0,n-1,n-1,maxi[n-1]);
        for(ll i=n-2;i>=0;i--){
            // [pos[i],pos[i]+nums[i])
            ll r=lower_bound(ALL(pos),pos[i]+nums[i])-pos.begin()-1;
            maxi[i]=clav.query(0,0,n-1,i,r);
            clav.update(0,0,n-1,i,maxi[i]);
        }
        if(maxi[0]==n-1){
            cout << "habibi\n";
            continue;
        }
        cout << "which\n";
    }
}