#include <bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
class Solution {
public:
    struct Segment{
        vector<int> freq;
        vector<pair<int,int>> a;
        void build(int node,int l,int r){
            if(l==r){
                freq[node]=a[l].second;
                return;
            }
            int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
            build(hiji,l,mid);
            build(hijd,mid+1,r);
            freq[node]=max(freq[hiji],freq[hijd]);
        }
        Segment(vector<pair<int,int>> temp){
            freq.resize(4*temp.size()+5);
            a=temp;
            build(0,0,a.size()-1);
        }
        int query(int node,int l,int r,int i,int j){
            if(r<i || j<l){
                return 0;
            }
            if(i<=l && r<=j){
                return freq[node];
            }
            int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
            return max(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
        }
    };
    int maxFrequency(vector<int>& nums, int k, int numOperations){
        int n=nums.size();
        sort(ALL(nums));
        vector<pair<int,int>> uniq;
        uniq.push_back({nums[0],1});
        for(int i=1;i<n;i++){
            if(nums[i]==uniq.back().first){
                uniq.back().second++;
            }else{
                uniq.push_back({nums[i],1});
            }
        }
        Segment resp(uniq);
        int l=1,r=n;
        while(l<r){
            int mid=(l+r+1)>>1;
            bool xd=false;
            for(int i=0;i<n-mid+1;i++){
                if(nums[i]+k>=nums[i+mid-1]-k){
                    if(mid<=numOperations){
                        xd=true;
                        break;
                    }
                    int iz=lower_bound(ALL(uniq),make_pair(nums[i+mid-1]-k,0))-uniq.begin();
                    int de=upper_bound(ALL(uniq),make_pair(nums[i]+k+1,0))-uniq.begin()-1;
                    if(iz<=de){
                        if(mid-resp.query(0,0,uniq.size()-1,iz,de)<=numOperations){
                            xd=true;
                            break;
                        }
                    }
                }
            }
            if(xd){
                l=mid;
            }else{
                r=mid-1;
            }
        }
        return l;
    }
};