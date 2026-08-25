#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid,int k){
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> res=grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int num=(i*m+j+k)%(n*m);
                res[num/m][num%m]=grid[i][j];
            }
        }
        return res;
    }
};