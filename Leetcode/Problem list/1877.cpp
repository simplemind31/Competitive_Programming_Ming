#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPairSum(vector<int>& nums){
        int mini,n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=mini=0;i<n/2;i++){
            mini=max(mini,nums[i]+nums[n-i-1]);
        }
        return mini;
    }
};