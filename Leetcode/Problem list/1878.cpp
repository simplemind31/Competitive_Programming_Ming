#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        vector<int> nums(3);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=grid[i][j];
                for(int i=0;i<3;i++){
                    if(sum==nums[i])break;
                    if(sum>nums[i])swap(sum,nums[i]);
                }
                for(int k=1;j+k<m && j-k>=0 && i+2*k<n;k++){
                    // long k
                    int sum=grid[i][j]+grid[i+2*k][j];
                    for(int l=1;l<=k;l++)sum+=grid[i+l][j-l]+grid[i+l][j+l]+grid[i+2*k-l][j-l]+grid[i+2*k-l][j+l];
                    sum-=grid[i+k][j-k]+grid[i+k][j+k];
                    for(int i=0;i<3;i++){
                        if(sum==nums[i])break;
                        if(sum>nums[i])swap(sum,nums[i]);
                    }
                }
            }
        }
        while(nums.back()==0)nums.pop_back();
        return nums;
    }
};