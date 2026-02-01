#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumCost(vector<int>& nums){
        int mini=150;
        for(int i=1,n=nums.size();i<n;i++){
            for(int j=i+1;j<n;j++){
                mini=min(mini,nums[i]+nums[j]+nums[0]);
            }
        }
        return mini;
    }
};