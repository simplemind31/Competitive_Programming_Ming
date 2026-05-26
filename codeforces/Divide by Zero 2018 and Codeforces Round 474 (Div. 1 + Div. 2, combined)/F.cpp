#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,res;
struct segment{
    int tam;
    vector<int> st;
    void update(int node,int l,int r,int pos,int val){
        if(l==r){
            st[node]=max(st[node],val);
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
        st[node]=max(st[hiji],st[hijd]); 
    }
    int query(int node,int l,int r,int i,int j){
        if(r<i || j<l)return 0;
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return max(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    segment(int x){
        tam=x;
        st.resize(4*tam);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    pair<pair<int,int>,int> edges[m];
    set<int> dif[n];
    vector<int> corres[n];
    vector<segment> lis(n,segment(0));
    for(int i=0;i<m;i++){
        cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
        dif[--edges[i].first.first].insert(edges[i].second);
        dif[--edges[i].first.second].insert(edges[i].second);
        // elegir el máximo del edges[i].first.first del rango [0,edges[i].second-1]
        // update edges[i].first.second en la posicion edges[i].second
    }
    for(int i=0;i<n;i++){
        corres[i]=vector(ALL(dif[i]));
        lis[i]=segment(corres[i].size());
    }
    for(int i=0;i<m;i++){
        int ma=lis[edges[i].first.first].query(0,0,corres[edges[i].first.first].size()-1,0,lower_bound(ALL(corres[edges[i].first.first]),edges[i].second)-corres[edges[i].first.first].begin()-1);
        res=max(res,ma+1);
        lis[edges[i].first.second].update(0,0,corres[edges[i].first.second].size(),lower_bound(ALL(corres[edges[i].first.second]),edges[i].second)-corres[edges[i].first.second].begin(),ma+1);
    }
    cout << res;
}