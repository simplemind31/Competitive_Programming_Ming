#include <bits/stdc++.h>
using namespace std;
struct segment{
    int tam;
    vector<pair<pair<int,int>,pair<bool,bool>>> st;
    // number of segment, total length, start with black, end with black?
    vector<int> lazy;
    // 0=nada,1=white 2=black
    void push_down(int node,int l,int r){
        if(!lazy[node])return;
        int hiji=2*node+1,hijd=2*node+2;
        if(l!=r){
            lazy[hiji]=lazy[node];
            lazy[hijd]=lazy[node];
        }
        if(lazy[node]==1)st[node]={{0,0},{0,0}};
        else st[node]={{1,r-l+1},{1,1}};
        lazy[node]=0;
    }
    pair<pair<int,int>,pair<bool,bool>> merge(pair<pair<int,int>,pair<bool,bool>> a,pair<pair<int,int>,pair<bool,bool>> b){
        pair<pair<int,int>,pair<bool,bool>> c;
        c.first.first=a.first.first+b.first.first-(a.second.second && b.second.first);
        c.first.second=a.first.second+b.first.second;
        c.second.first=a.second.first;
        c.second.second=b.second.second;
        return c;
    }
    void update(int node,int l,int r,int i,int j,int val){
        push_down(node,l,r);
        if(r<i || j<l)return;
        if(i<=l && r<=j){
            lazy[node]=val;
            push_down(node,l,r);
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        update(hiji,l,mid,i,j,val);
        update(hijd,mid+1,r,i,j,val);
        st[node]=merge(st[hiji],st[hijd]);
    }
    pair<pair<int,int>,pair<bool,bool>> query(int node,int l,int r,int i,int j){
        push_down(node,l,r);
        if(r<i || j<l)return {{0,0},{0,0}};
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return merge(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    segment(int x){
        tam=x;
        st.resize(4*tam+5);
        lazy.resize(4*tam+5);
    }
};
char c;
int n,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    segment clav(1000000);
    // 1=black 0white
    while(n--){
        cin >> c >> a >> b;
        a+=500000;
        // del a, a+b-1;
        if(c=='W')clav.update(0,0,1000000,a,a+b-1,1);
        else clav.update(0,0,1000000,a,a+b-1,2);
        clav.push_down(0,0,1000000);
        cout << clav.st[0].first.first << ' ' << clav.st[0].first.second << '\n';
    }
}