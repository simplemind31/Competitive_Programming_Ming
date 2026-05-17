
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums){
        //99901245999
        //[3,1,3,3]
        int mini=1e9;
        for(auto u:nums)mini=min(mini,u);
        return mini;
        int n=nums.size();
        if(n==1)return nums[0];
        if(nums[0]<nums[n-1])return nums[0];
        if(n==2)return nums[n-1];
        if(nums[0]==nums[n-1]){
            // puede que
        }
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(nums[0]==nums[mid])l=mid;
            else r=mid-1;
        }
        int iz=l;
        if(iz==n-1)return nums[0];
        l=iz+1,r=n-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(nums[0]<nums[mid])l=mid+1;
            else r=mid;
        }
        return nums[l];
    }
};