#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segment{
    ll tam;
    vector<ll> st;
    vector<pair<bool,ll>> lazy;
    // true= assign
    void apply(ll node,pair<bool,ll> op){
        if(op.first)lazy[node]=op;
        else lazy[node].second+=op.second;
    }
    void push_down(ll node,ll l,ll r){
        ll hiji=2*node+1,hijd=2*node+2;
        if(l!=r){
            apply(hiji,lazy[node]);
            apply(hijd,lazy[node]);
        }
        if(lazy[node].first)st[node]=lazy[node].second*(r-l+1);
        else st[node]+=lazy[node].second*(r-l+1);
        lazy[node]={0,0};
    }
    void update(ll node,ll l,ll r,ll i,ll j,pair<bool,ll> val){
        push_down(node,l,r);
        if(r<i || j<l)return;
        if(i<=l && r<=j){
            apply(node,val);
            push_down(node,l,r);
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        update(hiji,l,mid,i,j,val);
        update(hijd,mid+1,r,i,j,val);
        st[node]=st[hiji]+st[hijd];
    }
    ll query(ll node,ll l,ll r,ll i,ll j){
        push_down(node,l,r);
        if(r<i || j<l)return 0;
        if(i<=l && r<=j)return st[node];
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return query(hiji,l,mid,i,j)+query(hijd,mid+1,r,i,j);
    }
    segment(ll x){
        tam=x;
        st.resize(4*tam+5);
        lazy.resize(4*tam+5);
    }
};
ll n,q,a,b,c,d,e;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    segment clav(n+1);
    while(q--){
        cin >> a >> b;
        if(a==1){
            cin >> c >> d >> e;
            // añadir d al rango b-1,c-1=añadir en b-1 y quitar en c
            clav.update(0,0,n,b-1,b-1,{0,d});
            clav.update(0,0,n,c,c,{0,-d});
            // añadir progresion de e al rango b-1,c-1=añadir para cada b al c-1 y quitar en c
            if(b==c)continue;
            clav.update(0,0,n,b,c-1,{0,e});
            clav.update(0,0,n,c,c,{0,-e*(c-b)});
        }else{
            cout << clav.query(0,0,n,0,b-1) << '\n';
        }
    }
}
/*
b,a,a+i,a+2i,a+3i
*/