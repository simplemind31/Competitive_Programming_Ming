#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
class Solution{
public:
    struct Segment{
        int n;
        vector<ll> arr;
        vector<pair<ll,ll>> st;
        //min,max
        void build(int node,int l,int r){
            if(l==r){
                st[node]={arr[l],arr[l]};
                return;
            }
            int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
            build(hiji,l,mid);
            build(hijd,mid+1,r);
            st[node]={min(st[hiji].first,st[hijd].first),max(st[hiji].second,st[hijd].second)};
        }
        pair<ll,ll> query(int node,int l,int r,int i,int j){
            if(r<i || j<l)return {1e18,-1e18};
            if(i<=l && r<=j)return st[node];
            int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
            pair<ll,ll> izquier=query(hiji,l,mid,i,j);
            pair<ll,ll> derech=query(hijd,mid+1,r,i,j);
            return {min(izquier.first,derech.first),max(izquier.second,derech.second)};
        }
        Segment(vector<ll> a){
            arr=a;
            n=a.size();
            st.resize(4*n+5);
            build(0,0,n-1);
        }
    };
    ll maxSumTrionic(vector<int>& nums){
        int n=nums.size();
        ll res=-1e18;
        vector<ll> psum(n+1);
        for(int i=1;i<=n;i++){
            psum[i]=psum[i-1]+nums[i-1];
            cout << psum[i] << ' ';
        }
        cout << '\n';
        Segment clav(psum);
        vector<int> in,de;
        for(int i=0;i+1<n;i++){
            if(nums[i]<nums[i+1])in.push_back(i+1);
            else if(nums[i]>nums[i+1])de.push_back(i+1);
        }
        vector<pair<int,int>> increasing,decreasing;
        increasing.push_back({-1,-1});
        decreasing.push_back({-1,-1});
        for(auto u:in){
            if(u==increasing.back().second)increasing.back().second++;
            else increasing.push_back({u,u+1});
        }
        for(auto u:de){
            if(u==decreasing.back().second)decreasing.back().second++;
            else decreasing.push_back({u,u+1});
        }
        increasing.erase(increasing.begin());
        decreasing.erase(decreasing.begin());
        for(auto u:decreasing){
            int izq=lower_bound(ALL(increasing),make_pair(u.first,0))-increasing.begin()-1;
            int der=lower_bound(ALL(increasing),make_pair(u.second,0))-increasing.begin();
            if(izq<0 || der>increasing.size())continue;
            if(increasing[izq].second!=u.first || increasing[der].first!=u.second)continue;
            // maximo de increasing[de].first increasing[de].second;
            //cout << increasing[izq].first << ' ' << increasing[izq].second << ' ' << u.first << ' ' << u.second << ' ' << increasing[der].first << ' ' << increasing[der].second << '\n';
            res=max(res,clav.query(0,0,n,increasing[der].first+1,increasing[der].second).second-clav.query(0,0,n,increasing[izq].first-1,increasing[izq].second-2).first);
            cout << clav.query(0,0,n,increasing[der].first+1,increasing[der].second).second << ' ' << clav.query(0,0,n,increasing[izq].first-1,increasing[izq].second-2).first << '\n';
        }
        // simular decreasing, si los dos de al lado unen y son increasing, elegir mayor psum derecho y menor psum izquierdo;
        return res;
    }
};