#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid,int k){
        if(grid[0][0]>k)return 0;
        int n=grid.size(),m=grid[0].size(),con=1;
        for(int j=1;j<m;j++){
            grid[0][j]+=grid[0][j-1];
            if(grid[0][j]>k)break;
            con++;
        }
        for(int i=1;i<n;i++){
            grid[i][0]+=grid[i-1][0];
            if(grid[i][0]>k)break;
            con++;
            for(int j=1;j<m;j++){
                grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
                if(grid[i][j]>k)break;
                con++;
            }
        }
        return con;
    }
};