#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    void rotate(vector<vector<int>>& mat){
        vector<vector<int>> nue=mat;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)mat[i][j]=nue[j][n-i-1];
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target){
        n=mat.size();
        for(int i=0;i<4;i++){
            if(mat==target)return true;
            rotate(mat);
        }
        return false;
    }
};