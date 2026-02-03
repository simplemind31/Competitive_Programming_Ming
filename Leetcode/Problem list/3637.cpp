#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isTrionic(vector<int>& nums){
        int i=0,n=nums.size();
        while(i+1<n && nums[i+1]>nums[i])i++;
        if(i==0)return false;
        while(i+1<n && nums[i+1]<nums[i])i++;
        if(i==n-1)return false;
        while(i+1<n && nums[i+1]>nums[i])i++;
        if(i!=n-1)return false;
        return true;
    }
};