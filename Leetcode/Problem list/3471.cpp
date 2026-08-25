#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
class Solution {
public:
    int largestInteger(vector<int>& nums,int k){
        bool xd=true;
        int n=nums.size(),maxi=-1;
        if(n==1)return nums[0];
        if(k==1){
            // largest unique
            sort(ALL(nums));
            if(nums[n-1]!=nums[n-2])return nums[n-1];
            for(int i=n-3;i>0;i--)if(nums[i]!=nums[i+1] && nums[i]!=nums[i-1])return nums[i];
            if(nums[0]!=nums[1])return nums[0];
            return -1;
        }
        for(int i=0;i<n;i++)maxi=max(maxi,nums[i]);
        if(n<=k || k==1)return maxi;
        if(nums[0]<nums[n-1])reverse(ALL(nums));
        for(int i=1;i<n && xd;i++)if(nums[i]==nums[0])xd=false;
        if(xd)return nums[0];
        reverse(ALL(nums));
        xd=true;
        for(int i=1;i<n && xd;i++)if(nums[i]==nums[0])xd=false;
        if(xd)return nums[0];
        return -1;
    }
};