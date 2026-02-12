#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
class Solution {
public:
    struct segment{
        int n;
        vector<int> arr,lazy;
        vector<pair<int,int>> st;
        void propagate(int node,int l,int r){
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
            propagate(node,l,r);
            if(r<i ||j<l)return;
            if(i<=l && r<=j){
                lazy[node]+=val;
                propagate(node,l,r);
                return;
            }
            int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
            update(hiji,l,mid,i,j,val);
            update(hijd,mid+1,r,i,j,val);
            st[node]={min(st[hiji].first,st[hijd].first),max(st[hiji].second,st[hijd].second)};
        }
        void build(int node,int l,int r){
            if(l==r){
                st[node]={arr[l],arr[l]};
                return;
            }
            int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
            build(hiji,l,mid);
            build(hijd,mid+1,r);
            st[node]={min(st[hiji].first,st[hijd].first),max(st[hiji].second,st[hijd].second)};
        }
        pair<int,int> query(int node,int l,int r,int i,int j){
            propagate(node,l,r);
            if(r<i || j<l)return {1e9,-1e9};
            if(i<=l && r<=j)return st[node];
            int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
            pair<int,int> iz=query(hiji,l,mid,i,j),de=query(hijd,mid+1,r,i,j);
            return {min(iz.first,de.first),max(iz.second,de.second)};
        }
        segment(vector<int> a){
            arr=a;
            n=a.size();
            st.resize(4*n+5);
            lazy.resize(4*n+5);
            build(0,0,n-1);
        }
    };
    int longestBalanced(vector<int>& nums){
        int n=nums.size(),res=0;
        map<int,queue<int>> last;
        vector<int> psum(n+1);
        for(int i=0;i<n;i++){
            last[nums[i]].push(i);
            psum[i+1]=psum[i];
            if(last[nums[i]].size()==1){
                if(nums[i]&1)psum[i+1]++;
                else psum[i+1]--;
            }
        }
        segment clav(psum);
        for(int i=0;i<n;i++){
            // encontrar un j tal que [i,j] es balanceado
            // como solo considero de i adelante, entonces psum[i-1](actalizado)=0
            // necesito econtrar uno de j que sea 0;
            int l=i+res,r=n;
            while(l<r){
                int mid=(l+r+1)>>1;
                pair<int,int> ans=clav.query(0,0,n,mid,r);
                if(ans.first<=0 && ans.second>=0)l=mid;
                else r=mid-1;
            }
            res=max(res,l-(i+1)+1);
            // updateo la contribution
            if(nums[i]&1)clav.update(0,0,n,i+1,n,-1);
            else clav.update(0,0,n,i+1,n,1);
            last[nums[i]].pop();
            if(last[nums[i]].size()){
                if(nums[i]&1)clav.update(0,0,n,last[nums[i]].front()+1,n,1);
                else clav.update(0,0,n,last[nums[i]].front()+1,n,-1);
            }
        }
        return res;
    }
};