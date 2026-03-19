#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid){
        int n=grid.size(),m=grid[0].size(),res=0;
        vector<vector<pair<int,int>>> con(n+1,vector<pair<int,int>>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                con[i][j].first=con[i][j-1].first+con[i-1][j].first-con[i-1][j-1].first+(grid[i-1][j-1]=='X');
                con[i][j].second=con[i][j-1].second+con[i-1][j].second-con[i-1][j-1].second+(grid[i-1][j-1]=='Y');
                res+=(con[i][j].first==con[i][j].second && con[i][j].first>0);
            }
        }
        return res;
    }
};