#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid){
        bool xd;
        short n=grid.size(),m=grid[0].size(),maxi=0;
        vector<vector<unsigned int>> psum(n+1,vector<unsigned int>(m+1));
        for(short i=0;i<n;i++)for(short j=0;j<m;j++)psum[i+1][j+1]=psum[i][j+1]+psum[i+1][j]-psum[i][j]+grid[i][j];
        for(short i=1;i<=n;i++){
            if(n-i+1<=maxi)break;
            for(short j=1;j<=m;j++){
                for(short k=min(n-i,m-j)+1;k>=1;k--){
                    xd=true;
                    if((psum[i+k-1][j+k-1]-psum[i-1][j+k-1]-psum[i+k-1][j-1]+psum[i-1][j-1])%k)continue;
                    unsigned int sum1=0,sum2=0,targ=(psum[i+k-1][j+k-1]-psum[i-1][j+k-1]-psum[i+k-1][j-1]+psum[i-1][j-1])/k;
                    for(short l=i;l<=i+k-1 && xd;l++){
                        sum1+=grid[l-1][l-i+j-1];
                        sum2+=grid[i+k-1-(l-i)-1][l-i+j-1];
                        if(psum[i+k-1][j+l-i]-psum[i+k-1][j+l-i-1]-psum[i-1][j+l-i]+psum[i-1][j+l-i-1]!=targ || psum[l][j+k-1]-psum[l-1][j+k-1]-psum[l][j-1]+psum[l-1][j-1]!=targ)xd=false;
                    }
                    if(sum1!=targ || sum2!=targ)xd=false;
                    if(xd){
                        maxi=max(maxi,k);
                        break;
                    }
                }
            }
        }
        return maxi;
    }
};