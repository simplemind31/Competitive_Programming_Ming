#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass){
        vector<vector<double>> res(query_row+2,vector<double>(query_glass+2));
        res[0][0]=poured;
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=query_glass;j++){
                res[i+1][j]+=max((res[i][j]-1)/2,0.0);
                res[i+1][j+1]+=max((res[i][j]-1)/2,0.0);
                res[i][j]=min(res[i][j],1.0);
            }
        }
        return res[query_row][query_glass];
    }
};