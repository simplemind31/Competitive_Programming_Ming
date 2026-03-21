#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid,int k){
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> nums(n-k+1,vector<int>(m-k+1));
        for(int i=0;i<n-k+1;i++){
            for(int j=0;j<m-k+1;j++){
                vector<int> temp;
                for(int l=i;l<i+k;l++){
                    for(int ll=j;ll<j+k;ll++){
                        temp.push_back(grid[l][ll]);
                    }
                }
                sort(ALL(temp));
                nums[i][j]=1e9;
                for(int l=1;l<temp.size();l++){
                    if(temp[l]==temp[l-1])continue;
                    nums[i][j]=min(nums[i][j],temp[l]-temp[l-1]);
                }
                if(nums[i][j]==1e9)nums[i][j]=0;
            }
        }
        return nums;
    }
};