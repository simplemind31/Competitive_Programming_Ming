#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n,m,con;
    // ante 0 iz, 1 ab, 2 de 3 arr
    vector<vector<int>> G;
    bool di[6][4]={{1,0,1,0},{0,1,0,1},{0,0,1,1},{1,0,0,1},{0,1,1,0},{1,1,0,0}};
    pair<int,int> ne[4]={{0,1},{-1,0},{0,-1},{1,0}};
    bool valid(const pair<int,int>& x){return (x.first>=0 && x.first<n && x.second>=0 && x.second<m);}
    bool solve(const pair<int,int>& x,int ante){
        if(x==make_pair(0,0))con++;
        if(con>=2)return false;
        if(x==make_pair(n-1,m-1))return true;
        for(int i=0;i<4;i++){
            if((ante+2)%4==i || !di[G[x.first][x.second]-1][i])continue;
            pair<int,int> nue=x;
            nue.first+=ne[i].first;
            nue.second+=ne[i].second;
            if(!valid(nue))continue;
            if(!di[G[nue.first][nue.second]-1][(i+2)%4])continue;
            if(solve(nue,i))return true;
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid){
        con=0;
        n=grid.size(),m=grid[0].size();
        G=grid;
        return solve({0,0},0);
    }
};