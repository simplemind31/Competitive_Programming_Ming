#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid){
        int n=grid.size();
        vector<int> nums(n);
        for(int i=0;i<n;i++)for(int j=n-1;j>=0 && !grid[i][j];j--)nums[i]++;
        // i=n-i-1
        int con=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=n-i-1)continue;
            int j=i+1;
            for(;j<n && nums[j]<n-i-1;j++);
            if(j==n)return -1;
            //swap(i,j);
            while(j>i){
                swap(nums[j],nums[j-1]);
                con++;
                j--;
            }
        }
        return con;
    }
};