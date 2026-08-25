#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct segment{
        int tam;
        string a;
        vector<pair<pair<pair<pair<pair<int,int>,int>,int>,int>,int>> st;
        // ans, todo igual a x, empieza con x, termina con x, maximo prefix, maximo sufix
        pair<pair<pair<pair<pair<int,int>,int>,int>,int>,int> merge(pair<pair<pair<pair<pair<int,int>,int>,int>,int>,int> x,pair<pair<pair<pair<pair<int,int>,int>,int>,int>,int> y){
            pair<pair<pair<pair<pair<int,int>,int>,int>,int>,int> res;
            res.first.first.first.first.first=max(x.first.first.first.first.first,y.first.first.first.first.first);
            if(x.first.first.second==y.first.first.first.second)res.first.first.first.first.first=max(res.first.first.first.first.first,x.second+y.first.second);
            if(x.first.first.first.first.second==y.first.first.first.first.second)res.first.first.first.first.second=x.first.first.first.first.second;
            else res.first.first.first.first.second=-1;
            res.first.first.first.second=x.first.first.first.second;
            res.first.first.second=y.first.first.second;
            if(x.first.first.second==y.first.first.first.second && x.first.first.first.first.second!=-1)res.first.second=x.first.first.first.first.first+y.first.second;
            else res.first.second=x.first.second;
            if(x.first.first.second==y.first.first.first.second && y.first.first.first.first.second!=-1)res.second=y.first.first.first.first.first+x.second;
            else res.second=y.second;
            return res;
        }
        void build(int node,int l,int r){
            if(l==r){
                st[node]={{{{{1,a[l]-'a'},a[l]-'a'},a[l]-'a'},1},1};
                return;
            }
            int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
            build(hiji,l,mid);
            build(hijd,mid+1,r);
            st[node]=merge(st[hiji],st[hijd]);
        }
        int query(){return st[0].first.first.first.first.first;}
        void update(int node,int l,int r,int pos,char val){
            if(l==r){
                a[l]=val;
                st[node]={{{{{1,a[l]-'a'},a[l]-'a'},a[l]-'a'},1},1};
                return;
            }
            int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
            if(pos<=mid)update(hiji,l,mid,pos,val);
            else update(hijd,mid+1,r,pos,val);
            st[node]=merge(st[hiji],st[hijd]);
        }
        segment(string x){
            a=x;
            tam=x.size();
            st.resize(4*tam);
            build(0,0,tam-1);
        }
    };
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices){
        int q=queryCharacters.size(),n=s.size();
        segment clav(s);
        vector<int> res(q);
        for(int i=0;i<q;i++){
            clav.update(0,0,n-1,queryIndices[i],queryCharacters[i]);
            res[i]=clav.query();
        }
        return res;
    }
};