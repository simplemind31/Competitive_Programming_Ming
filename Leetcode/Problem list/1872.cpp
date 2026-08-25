#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct segment{
        int tam;
        vector<int> lazy;
        vector<pair<int,int>> st;
        void pushdown(int node,int l,int r){
            st[node].first+=lazy[node];
            st[node].second+=lazy[node];
            if(l!=r){
                int hiji=2*node+1,hijd=2*node+2;
                lazy[hiji]+=lazy[node];
                lazy[hijd]+=lazy[node];
            }
            lazy[node]=0;
        }
        void update(int node,int l,int r,int i,int j,int val){
            pushdown(node,l,r);
            if(r<i || j<l)return;
            if(i<=l && r<=j){
                lazy[node]+=val;
                pushdown(node,l,r);
                return;
            }
            int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
            update(hiji,l,mid,i,j,val);
            update(hijd,mid+1,r,i,j,val);
            st[node]={min(st[hiji].first,st[hijd].first),max(st[hiji].second,st[hijd].second)};
        }
        pair<int,int> query(int node,int l,int r,int i,int j){
            pushdown(node,l,r);
            if(r<i || j<l)return {1e9,-1e9};
            if(i<=l && r<=j)return st[node];
            int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
            pair<int,int> iz=query(hiji,l,mid,i,j),de=query(hijd,mid+1,r,i,j);
            return {min(iz.first,de.first),max(iz.second,de.second)};
        }
        segment(int x){
            tam=x;
            lazy.resize(4*x);
            st.resize(4*x);
        }
    };
    int stoneGameVIII(vector<int>& stones){
        int n=stones.size(),psum[n];
        psum[0]=stones[0];
        for(int i=1;i<n;i++)psum[i]=psum[i-1]+stones[i];
        vector<segment> nue(2,segment(n));
        // nue[i][j]->j=0->the score if we have to pick from the ith to (n-1)th in A,j=1-> B
        nue[0].update(0,0,n-1,n-1,n-1,-psum[n-1]);
        nue[1].update(0,0,n-1,n-1,n-1,psum[n-1]);
        for(int i=n-2;i>=0;i--){
            nue[0].update(0,0,n-1,i,i,nue[1].query(0,0,n-1,i+1,n-1).second-psum[i]);
            nue[1].update(0,0,n-1,i,i,nue[0].query(0,0,n-1,i+1,n-1).first+psum[i]);
        }
        return nue[0].query(0,0,n-1,0,0).first+psum[0];
    }
};