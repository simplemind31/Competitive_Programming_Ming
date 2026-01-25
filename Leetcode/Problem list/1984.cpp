#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums,int k){
        int mini=1e9;
        sort(nums.begin(),nums.end());
        for(int i=0,n=nums.size();i+k-1<n;i++){
            mini=min(nums[i+k-1]-nums[i],mini);
        }
        return mini;
    }
};