#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int l,int r, vector<int>& nums){
        if(l>r)return 0;
        if(dp[l][r]!=1e9)return dp[l][r];
        if(!(((r-l+1)-n)&1))return dp[l][r]=max(nums[l]+solve(l+1,r,nums),solve(l,r-1,nums)+nums[r]);
        else return dp[l][r]=min(-nums[l]+solve(l+1,r,nums),solve(l,r-1,nums)-nums[r]);
    }
    bool stoneGame(vector<int>& nums){
        n=nums.size();
        dp.assign(n,vector<int>(n,1e9));
        return solve(0,n-1,nums)>=0;
    }
};