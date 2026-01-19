#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n,m,ans,val;
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        n=mat.size();
        m=mat[ans=0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i)mat[i][j]+=mat[i-1][j];
                if(j)mat[i][j]+=mat[i][j-1];
                if(i && j)mat[i][j]-=mat[i-1][j-1];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=ans+1;i+k-1<n && j+k-1<m;k++){
                    val=mat[i+k-1][j+k-1];
                    if(i)val-=mat[i-1][j+k-1];
                    if(j)val-=mat[i+k-1][j-1];
                    if(i && j)val+=mat[i-1][j-1];
                    if(val<=threshold)ans++;
                    else break;
                }
            }
        }
        return ans;
    }
};