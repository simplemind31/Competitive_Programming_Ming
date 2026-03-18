#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix){
        int n=matrix.size(),m=matrix[0].size(),res=0;
        for(int j=0;j<m;j++){
            for(int i=n-2;i>=0;i--){
                if(matrix[i][j]==1)matrix[i][j]+=matrix[i+1][j];
            }
        }
        for(int i=0;i<n && (n-i)*m>res;i++){
            sort(REV(matrix[i]));
            for(int j=0;j<m && matrix[i][j]*m>res;j++){
                if(matrix[i][j]*(j+1)>res)res=matrix[i][j]*(j+1);
            }
        }
        return res;
    }
};