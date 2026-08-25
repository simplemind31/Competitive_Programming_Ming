#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0,n=nums.size(),maxi=0;
        unordered_map<int,int> con;
        for(int r=0;r<n;r++){
            con[nums[r]]++;
            while(con[nums[r]]>k)con[nums[l++]]--;
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};