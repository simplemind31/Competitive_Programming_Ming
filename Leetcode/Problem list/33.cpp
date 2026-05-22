#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int search(vector<int>& nums,int target){
        short n=nums.size();
        if(nums[0]<=nums[n-1]){
            short l=0,r=n-1;
            while(l<r){
                int mid=(l+r)>>1;
                if(nums[mid]==target)return mid;
                if(nums[mid]>target)r=mid-1;
                else l=mid+1;
            }
            if(l<0 || r>=n)return -1;
            return nums[l]==target?l:-1;
        }
        short l=1,r=n-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(nums[mid]>nums[0])l=mid+1;
            else r=mid;
        }
        short ini=l;
        if(target>=nums[0])l=0,r=ini-1;
        else l=ini,r=n-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)r=mid-1;
            else l=mid+1;
        }
        if(l<0 || l>=n)return -1;
        return nums[l]==target?l:-1;
    }
};