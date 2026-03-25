#include <bits/stdc++.h>
#define MOD 12345
using namespace std;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> pmult(n+2,vector<int>(m+2,1)),smult(pmult),izmult(pmult),demult(pmult);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)izmult[i][j]=grid[i-1][j-1]%MOD*izmult[i][j-1]%MOD;
            for(int j=1;j<=m;j++)pmult[i][j]=izmult[i][j]*pmult[i-1][j]%MOD;
        }
        for(int i=n;i>0;i--){
            for(int j=m;j>0;j--)demult[i][j]=grid[i-1][j-1]%MOD*demult[i][j+1]%MOD;
            for(int j=m;j>0;j--)smult[i][j]=demult[i][j]*smult[i+1][j]%MOD;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=pmult[i][m]*smult[i+2][1]%MOD*izmult[i+1][j]%MOD*demult[i+1][j+2]%MOD;
            }
        }
        return grid;
    }
};