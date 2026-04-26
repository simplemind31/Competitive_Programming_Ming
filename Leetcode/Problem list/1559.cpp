#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n,m;
    vector<vector<char>> mat;
    vector<vector<bool>> visited;
    bool solve(int x,int y,char c,int antex,int antey){
        if(x<0 || y<0 || x>=n || y>=m)return false;
        if(mat[x][y]!=c)return false;
        if(visited[x][y])return true;
        visited[x][y]=true;
        if((x-1!=antex || y!=antey) && solve(x-1,y,c,x,y))return true;
        if((x+1!=antex || y!=antey) && solve(x+1,y,c,x,y))return true;
        if((x!=antex || y-1!=antey) && solve(x,y-1,c,x,y))return true;
        if((x!=antex || y+1!=antey) && solve(x,y+1,c,x,y))return true;
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid){
        n=grid.size(),m=grid[0].size();
        mat=grid;
        visited.assign(n,vector<bool>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j])continue;
                if(solve(i,j,grid[i][j],-1,-1))return true;
            }
        }
        return false;
    }
};