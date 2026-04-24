#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a;
ll res=0;
// simular el minimo, siempre quitar si l<=i<=r
// maxsegment
struct segment{
    int tam;
    vector<ll> a,st,lazy;
    void push_down(int node,int l,int r){
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        if(l!=r){
            lazy[hiji]+=lazy[node];
            lazy[hijd]+=lazy[node];
        }
        st[node]+=lazy[node];
        lazy[node]=0;
    }
    void build(int node,int l,int r){
        if(l==r){
            st[node]=a[l];
            return;
        }
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=max(st[hiji],st[hijd]);
    }
    void update(int node,int l,int r,int i,int j,int a){
        push_down(node,l,r);
        if(r<i || j<l)return;
        if(i<=l && r<=j){
            lazy[node]+=a;
            push_down(node,l,r);
            return;
        }
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        update(hiji,l,mid,i,j,a);
        update(hijd,mid+1,r,i,j,a);
        st[node]=max(st[hiji],st[hijd]);
    }
    ll query(int node,int l,int r,int i,int j){
        push_down(node,l,r);
        if(r<i || j<l)return -1e18;
        if(i<=l && r<=j)return st[node];
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        return max(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    segment(vector<ll> x){
        tam=x.size();
        a=x;
        st.resize(4*tam+5);
        lazy.resize(4*tam+5);
        build(0,0,tam-1);
    }
};
segment clav({1,2});
vector<int> resp;
void parallel(int l,int r,vector<pair<pair<int,int>,int>>& query,vector<int>& elegido){
    int mid=(l+r)>>1;
    vector<pair<pair<int,int>,int>> iz,de;
    for(auto u:query){
        if(u.first.first<=l && r<=u.first.second){
            clav.update(0,0,n-1,u.first.first,u.first.second,-1);
            elegido.push_back(u.second);
        }else{
            if(u.first.first<=mid)iz.push_back(u);
            if(u.first.second>=mid+1)de.push_back(u);
        }
    }
    if(l==r){
        ll temp=clav.query(0,0,n-1,0,n-1)-clav.query(0,0,n-1,l,l);
        if(temp>res){
            res=temp;
            // todos los que no estan en query
            resp=elegido;
        }
        for(auto u:query){
            if(u.first.first<=l && r<=u.first.second){
                clav.update(0,0,n-1,u.first.first,u.first.second,1);
                elegido.pop_back();
            }
        }
        return;
    }
    parallel(l,mid,iz,elegido);
    parallel(mid+1,r,de,elegido);
    for(auto u:query){
        if(u.first.first<=l && r<=u.first.second){
            clav.update(0,0,n-1,u.first.first,u.first.second,1);
            elegido.pop_back();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<ll> nums(n);
    for(int i=0;i<n;i++)cin >> nums[i];
    clav=segment(nums);
    vector<pair<pair<int,int>,int>> queries(m);
    for(int i=0;i<m;i++){
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].first.first--;
        queries[i].first.second--;
        queries[i].second=i;
    }
    vector<int> nada;
    parallel(0,n-1,queries,nada);
    cout << res << '\n';
    cout << resp.size() << '\n';
    for(auto u:resp)cout << u+1 << ' ';
}