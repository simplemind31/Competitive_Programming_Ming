#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pll; 
int n,q,t,a,b;
//min,max, res/best combination of a segment
struct segment{
    vector<pair<pll,pll>> st;
    vector<ll> arr;
    pll merge1(pll x,pll y){
        pll res;
        if(arr[x.first]<arr[y.first])res.first=x.first;
        else res.first=y.first;
        if(arr[x.second]<arr[y.second])res.second=y.second;
        else res.second=x.second;
        return res;
    }
    pll merge2(pll x,pll y){
        if(arr[x.second]-arr[x.first]==arr[y.second]-arr[y.first]){
            if(x.second-x.first<y.second-y.first)return x;
            else return y;
        }
        if(arr[x.second]-arr[x.first]>arr[y.second]-arr[y.first])return x;
        else return y;
    }
    void build(int node,int l,int r){
        if(l==r){
            st[node]={{l-1,r},{l-1,r}};
            return;
        }
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node].first=merge1(st[hiji].first,st[hijd].first);
        st[node].second=merge2(merge2(st[hiji].second,st[hijd].second),{st[hiji].first.first,st[hijd].first.second});
    }
    pair<pll,pll> query(int node,int l,int r,int i,int j){
        if(r<i || j<l)return {{-1,-1},{-1,-1}};
        if(i<=l && r<=j)return st[node];
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        pair<pll,pll> iz=query(hiji,l,mid,i,j),de=query(hijd,mid+1,r,i,j);
        if(iz==make_pair(make_pair(-1ll,-1ll),make_pair(-1ll,-1ll)))return de;
        if(de==make_pair(make_pair(-1ll,-1ll),make_pair(-1ll,-1ll)))return iz;
        pair<pll,pll> res;
        res.first=merge1(iz.first,de.first);
        res.second=merge2(merge2(iz.second,de.second),{iz.first.first,de.first.second});
        return res;
    }
    segment(vector<ll> x){
        st.resize(4*n+4);
        arr=x;
        build(0,1,n);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> q;
        // psum[r]-psum[l-1]-pxor[r]^pxor[l-1];
        ll psum[n+1],pxor[n+1];
        vector<ll> f(n+1);
        psum[0]=pxor[0]=f[0]=0;
        for(int i=1;i<=n;i++){
            cin >> a;
            psum[i]=psum[i-1]+a;
            pxor[i]=pxor[i-1]^a;
            f[i]=psum[i]-pxor[i];
        }
        for(int i=1;i<=n;i++)cout << psum[i] << ' ';
        cout << '\n';
        for(int i=1;i<=n;i++)cout << pxor[i] << ' ';
        cout << '\n';
        for(int i=1;i<=n;i++)cout << f[i] << ' ';
        cout << '\n';
        segment res(f);
        while(q--){
            cin >> a >> b;
            pll ans=res.query(0,1,n,a,b).second;
            cout << ans.first+1 << ' ' << ans.second << '\n';
        }
    }
}