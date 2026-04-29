#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(auto u:grid){
            for(auto v:u){
                nums.push_back(v);
                if((v-grid[0][0])%x)return -1;
            }
        }
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=0;
        for(auto u:nums){
            res+=abs(u-nums[n/2])/x;
        }
        return res;
    }
};