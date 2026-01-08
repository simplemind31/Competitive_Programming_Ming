#include <bits/stdc++.h>
using namespace std;
int q;
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries){
        vector<vector<int>> mat(n,vector<int>(n,0));
        q=queries.size();
        for(int i=0;i<q;i++){
            mat[queries[i][0]][queries[i][1]]++;
            if(queries[i][2]+1<n)mat[queries[i][2]+1][queries[i][1]]--;
            if(queries[i][3]+1<n)mat[queries[i][0]][queries[i][3]+1]--;
            if(queries[i][2]+1<n && queries[i][3]+1<n)mat[queries[i][2]+1][queries[i][3]+1]++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i)mat[i][j]+=mat[i-1][j];
                if(j)mat[i][j]+=mat[i][j-1];
                if(i&&j)mat[i][j]-=mat[i-1][j-1];
            }
        }
        return mat;
    }
};