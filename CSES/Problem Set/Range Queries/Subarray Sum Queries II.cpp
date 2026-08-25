#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segment{
    ll tam;
    vector<ll> res,a,pre,suf,tot;
    void build(ll node,ll l,ll r){
        if(l==r){
            res[node]=pre[node]=suf[node]=tot[node]=a[l];
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        pre[node]=max(pre[hiji],tot[hiji]+pre[hijd]);
        suf[node]=max(suf[hijd],tot[hijd]+suf[hiji]);
        tot[node]=tot[hiji]+tot[hijd];
        res[node]=max({res[hiji],res[hijd],pre[hijd]+suf[hiji]});
    }
    void update(ll node,ll l,ll r,ll pos,ll val){
        if(l==r){
            res[node]=pre[node]=suf[node]=tot[node]=a[l]=val;
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
        pre[node]=max(pre[hiji],tot[hiji]+pre[hijd]);
        suf[node]=max(suf[hijd],tot[hijd]+suf[hiji]);
        tot[node]=tot[hiji]+tot[hijd];
        res[node]=max({res[hiji],res[hijd],pre[hijd]+suf[hiji]});
    }
    pair<pair<ll,ll>,pair<ll,ll>> query(ll node,ll l,ll r,ll i,ll j){
        if(r<i || j<l)return {{-1e14,-1e14},{-1e14,-1e14}};
        if(i<=l && r<=j)return {{pre[node],suf[node]},{tot[node],res[node]}};
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        pair<pair<ll,ll>,pair<ll,ll>> iz=query(hiji,l,mid,i,j),de=query(hijd,mid+1,r,i,j);
        pair<pair<ll,ll>,pair<ll,ll>> now;
        now.first.first=max(iz.first.first,iz.second.first+de.first.first);
        now.first.second=max(de.first.second,de.second.first+iz.first.second);
        now.second.first=iz.second.first+de.second.first;
        now.second.second=max({iz.second.second,de.second.second,de.first.first+iz.first.second});
        return now;
    }
    segment(vector<ll> x){
        a=x;
        tam=a.size();
        res.resize(4*tam);
        pre=suf=tot=res;
        build(0,0,tam-1);
    }
};
ll n,q,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    vector<ll> nums(n);
    for(ll i=0;i<n;i++)cin >> nums[i];
    segment clav(nums);
    while(q--){
        cin >> a >> b;
        cout << max(clav.query(0,0,n-1,a-1,b-1).second.second,0ll) << '\n';
    }
}