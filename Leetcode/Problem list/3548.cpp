#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        ll sumatotal=0,sumanow=0;
        vector<int> conta(1e5+1),conta2(1e5+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sumanow+=grid[i][j];
                conta[grid[i][j]]++;
            }
        }
        sumatotal=sumanow;
        if(n==1){
            for(int j=0;j<m-1;j++){
                conta[grid[0][j]]--;
                conta2[grid[0][j]]++;
                sumanow-=grid[0][j];
                if(sumanow*2==sumatotal)return true;
                if(abs(sumanow-(sumatotal-sumanow))>1e5)continue;
                if(sumanow*2>sumatotal){
                    if(grid[0][m-1]==abs(sumanow-(sumatotal-sumanow)) || grid[0][j+1]==abs(sumanow-(sumatotal-sumanow)))return true;
                }else{
                    if(grid[0][0]==abs(sumanow-(sumatotal-sumanow)) || grid[0][j]==abs(sumanow-(sumatotal-sumanow)))return true;
                }
            }
            return false;
        }else if(m==1){
            for(int i=0;i<n-1;i++){
                conta[grid[i][0]]--;
                conta2[grid[i][0]]++;
                sumanow-=grid[i][0];
                if(sumanow*2==sumatotal)return true;
                if(abs(sumanow-(sumatotal-sumanow))>1e5)continue;
                if(sumanow*2>sumatotal){
                    if(grid[n-1][0]==abs(sumanow-(sumatotal-sumanow)) || grid[i+1][0]==abs(sumanow-(sumatotal-sumanow)))return true;
                }else{
                    if(grid[0][0]==abs(sumanow-(sumatotal-sumanow)) || grid[i][0]==abs(sumanow-(sumatotal-sumanow)))return true;
                }
            }
            return false;
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                conta[grid[i][j]]--;
                conta2[grid[i][j]]++;
                sumanow-=grid[i][j];
            }
            if(sumanow*2==sumatotal)return true;
            if(abs(sumanow-(sumatotal-sumanow))>1e5)continue;
            if(sumanow*2>sumatotal){
                if(i+1!=n-1 && conta[abs(sumanow-(sumatotal-sumanow))])return true;
                if(grid[i+1][0]==abs(sumanow-(sumatotal-sumanow)) || grid[i+1][m-1]==abs(sumanow-(sumatotal-sumanow)))return true;
            }else{
                // quitar de conta 2
                if(i && conta2[abs(sumanow-(sumatotal-sumanow))])return true;
                if(grid[i][0]==abs(sumanow-(sumatotal-sumanow)) || grid[i][m-1]==abs(sumanow-(sumatotal-sumanow)))return true;
            }
        }
        sumanow=0;
        conta.clear();
        conta2.clear();
        conta.shrink_to_fit();
        conta2.shrink_to_fit();
        conta.resize(1e5+1);
        conta2.resize(1e5+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sumanow+=grid[i][j];
                conta[grid[i][j]]++;
            }
        }
        for(int j=0;j<m-1;j++){
            for(int i=0;i<n;i++){
                conta[grid[i][j]]--;
                conta2[grid[i][j]]++;
                sumanow-=grid[i][j];
            }
            if(sumanow*2==sumatotal)return true;
            if(abs(sumanow-(sumatotal-sumanow))>1e5)continue;
            if(sumanow*2>sumatotal){
                if(j+1!=m-1 && conta[abs(sumanow-(sumatotal-sumanow))])return true;
                if(grid[0][j+1]==abs(sumanow-(sumatotal-sumanow)) || grid[n-1][j+1]==abs(sumanow-(sumatotal-sumanow)))return true;
            }else{
                // quitar de conta 2
                if(j && conta2[abs(sumanow-(sumatotal-sumanow))])return true;
                if(grid[0][j]==abs(sumanow-(sumatotal-sumanow)) || grid[n-1][j]==abs(sumanow-(sumatotal-sumanow)))return true;
            }
        }
        return false;
    }
};