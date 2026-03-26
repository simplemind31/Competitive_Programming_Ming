#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        vector<vector<ll>> psum(n,vector<ll>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                psum[i][j]=grid[i][j];
                if(i)psum[i][j]+=psum[i-1][j];
                if(j)psum[i][j]+=psum[i][j-1];
                if(i&&j)psum[i][j]-=psum[i-1][j-1];
            }
        }
        for(int i=1;i<n;i++){
            if(2*psum[i-1][m-1]==psum[n-1][m-1])return true;
        }
        for(int i=1;i<m;i++){
            if(2*psum[n-1][i-1]==psum[n-1][m-1])return true;
        }
        return false;
    }
};