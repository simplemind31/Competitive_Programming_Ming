#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,t,a,b,c;
pair<pair<ll,ll>,pair<ll,ll>> imposi={{-1,-1},{-1,-1}};
pair<pair<ll,ll>,pair<ll,ll>> combi(pair<pair<ll,ll>,pair<ll,ll>> f, pair<pair<ll,ll>,pair<ll,ll>> s){
    f.first.first=max(s.first.first,f.first.first);
    f.first.second=max(f.first.second,s.first.second);
    f.second.first=max(f.second.first,s.second.first);
    f.second.second=max(f.second.second,s.second.second);
    return f;
}
struct segment{
    vector<pair<pair<ll,ll>,pair<ll,ll>>> st;
    void update(ll node, ll l, ll r, ll i, ll j, pair<pair<ll,ll>,pair<ll,ll>> val){
        if(i<=l && r<=j){
            st[node]=combi(st[node],val);
            return;
        }
        if(r<i || j<l)return;
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        update(hiji,l,mid,i,j,val);
        update(hijd,mid+1,r,i,j,val);
    }
    pair<pair<ll,ll>,pair<ll,ll>> query(ll node, ll l, ll r, ll pos){
        if(l==r){
            return st[node];
        }
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        st[hiji]=combi(st[hiji],st[node]);
        st[hijd]=combi(st[hijd],st[node]);
        if(pos<=mid)return query(hiji,l,mid,pos);
        return query(hijd,mid+1,r,pos);
    }
    segment(ll n){
        st.assign(4*n+5,{{0,0},{0,0}});
    }
};
pair<pair<ll,ll>,pair<ll,ll>> divi(ll x){
    pair<pair<ll,ll>,pair<ll,ll>> res={{0,0},{0,0}};
    while(x%2==0){
        res.first.first++;
        x/=2;
    }
    while(x%3==0){
        res.first.second++;
        x/=3;
    }
    while(x%5==0){
        res.second.first++;
        x/=5;
    }
    while(x%7==0){
        res.second.second++;
        x/=7;
    }
    if(x!=1)return imposi;
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    segment arbo(n);
    while(q--){
        cin >> t;
        if(t==1){
            cin >> a >> b >> c;
            arbo.update(0,0,n-1,a,b,divi(c));
        }else{
            cin >> a >> c;
            pair<pair<ll,ll>,pair<ll,ll>> nu=arbo.query(0,0,n-1,a);
            pair<pair<ll,ll>,pair<ll,ll>> che=divi(c);
            if(che==imposi)cout <<"NO\n";
            else if(che.first.first<=nu.first.first && che.first.second<=nu.first.second && che.second.first<=nu.second.first && che.second.second<=nu.second.second)cout << "YES\n";
            else cout << "NO\n";
        }
    }
}