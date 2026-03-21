#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int j=y;j<y+k;j++){
            for(int i=x;i<x+k/2;i++){
                swap(grid[i][j],grid[x+k-1-(i-x)][j]);
            }
        }
        return grid;
    }
};