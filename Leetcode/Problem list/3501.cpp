#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    struct segment{
        int tam;
        vector<pair<int,int>> a;
        vector<int> st;
        void build(int node,int l,int r){
            if(l==r){
                if(!(l&1) && l && l+1<tam)st[node]=a[l-1].second-a[l-1].first+1+a[l+1].second-a[l+1].first+1;
                return;
            }
            int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
            build(hiji,l,mid);
            build(hijd,mid+1,r);
            st[node]=max(st[hiji],st[hijd]);
        }
        int query(int node,int l,int r,int i,int j){
            int ll=l,rr=r;
            while(ll==0 || ll&1)ll++;
            while(rr==tam-1 || rr&1)rr--;
            if(ll>rr || j<a[ll-1].first || a[rr+1].second<i)return 0;
            if(i<=a[ll-1].first && a[rr+1].second<=j)return st[node];
            if(ll==rr){
                int iz=a[ll-1].second-max(a[ll-1].first,i)+1,de=min(j,a[rr+1].second)-a[rr+1].first+1;
                if(iz<=0 || de<=0)return 0;
                return iz+de;
            }
            int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
            return max(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
        }
        segment(vector<pair<int,int>> x){
            a=x;
            tam=a.size();
            st.resize(4*tam);
            build(0,0,tam-1);
        }
    };
    vector<int> maxActiveSectionsAfterTrade(string s,vector<vector<int>>& queries){
        int n=s.size(),q=queries.size(),tot=0;
        vector<int> res(q);
        vector<pair<int,int>> nums;
        if(s[0]=='0')nums.push_back({0,-1});
        nums.push_back({0,0});
        tot+=(s[0]=='1');
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])nums.back().second++;
            else nums.push_back({i,i});
            tot+=(s[i]=='1');
        }
        if(s[n-1]=='0')nums.push_back({n,n-1});
        segment clav(nums);
        for(int i=0;i<q;i++)res[i]=clav.query(0,0,clav.tam-1,queries[i][0],queries[i][1])+tot;
        return res;
    }
};