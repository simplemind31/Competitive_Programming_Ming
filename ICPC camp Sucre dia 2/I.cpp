#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
// encontrar el primer elemento menor igual
struct segment{
    int tam;
    vector<int> a,st;
    void build(int node,int l,int r){
        if(l==r){
            st[node]=a[l];
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=min(st[hiji],st[hijd]);
    }
    int query(int node,int l,int r,int i,int j,int val){
        if(r<i || j<l)return -1;
        if(st[node]>val)return -1;
        if(l==r)return l;
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        int res=query(hiji,l,mid,i,j,val);
        if(res!=-1)return res;
        return query(hijd,mid+1,r,i,j,val);
    }
    segment(vector<int> x){
        tam=x.size();
        a=x;
        st.resize(4*tam+5);
        build(0,0,tam-1);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<int> a(n),e(m);
    for(int i=0;i<n;i++)cin >> a[i];
    // take modulo, tomará a lo mucho log n modulos
    for(int j=0;j<m;j++)cin >> e[j];
    segment clav(e);
    for(int i=0;i<n;i++){
        int last=0;
        while(last<m){
            int pos=clav.query(0,0,m-1,last,m-1,a[i]);
            if(pos==-1)break;
            a[i]%=e[pos];
            last=pos+1;
        }
        cout << a[i] << ' ';
    }
}