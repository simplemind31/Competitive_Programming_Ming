#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        vector<vector<ll>> neg(n,vector<ll>(m)),pos(n,vector<ll>(m));
        vector<vector<bool>> negbool(n,vector<bool>(m)),posbool(n,vector<bool>(m));
        if(grid[0][0]>=0){
            pos[0][0]=grid[0][0];
            posbool[0][0]=true;
        }else{
            neg[0][0]=grid[0][0];
            negbool[0][0]=true;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j){
                    if(grid[i][j]>0){
                        posbool[i][j]=posbool[i][j]|posbool[i][j-1];
                        negbool[i][j]=negbool[i][j]|negbool[i][j-1];
                        pos[i][j]=max(pos[i][j],grid[i][j]*pos[i][j-1]);
                        neg[i][j]=min(neg[i][j],grid[i][j]*neg[i][j-1]);
                    }else if(grid[i][j]<0){
                        posbool[i][j]=posbool[i][j]|negbool[i][j-1];
                        negbool[i][j]=negbool[i][j]|posbool[i][j-1];
                        pos[i][j]=max(pos[i][j],grid[i][j]*neg[i][j-1]);
                        neg[i][j]=min(neg[i][j],grid[i][j]*pos[i][j-1]);
                    }
                }
                if(i){
                    if(grid[i][j]>0){
                        posbool[i][j]=posbool[i][j]|posbool[i-1][j];
                        negbool[i][j]=negbool[i][j]|negbool[i-1][j];
                        pos[i][j]=max(pos[i][j],grid[i][j]*pos[i-1][j]);
                        neg[i][j]=min(neg[i][j],grid[i][j]*neg[i-1][j]);
                    }else if(grid[i][j]<0){
                        posbool[i][j]=posbool[i][j]|negbool[i-1][j];
                        negbool[i][j]=negbool[i][j]|posbool[i-1][j];
                        pos[i][j]=max(pos[i][j],grid[i][j]*neg[i-1][j]);
                        neg[i][j]=min(neg[i][j],grid[i][j]*pos[i-1][j]);
                    }
                }
                if(grid[i][j]==0){
                    posbool[i][j]=negbool[i][j]=true;
                }
            }
        }
        if(!posbool[n-1][m-1])return -1;
        return pos[n-1][m-1]%MOD;
    }
};