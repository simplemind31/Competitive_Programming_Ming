#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid,int k){
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<min(n,m)/2;i++){
            int nue=k%(2*(n-2*i)+2*(m-2*i)-4);
            while(nue--){
                int now=i;
                while(now<m-i-1){
                    swap(grid[i][now],grid[i][now+1]);
                    now++;
                }
                now=i;
                while(now<n-i-1){
                    swap(grid[now][m-i-1],grid[now+1][m-i-1]);
                    now++;
                }
                now=m-i-1;
                while(now>i){
                    swap(grid[n-i-1][now],grid[n-i-1][now-1]);
                    now--;
                }
                now=n-i-1;
                while(now>i+1){
                    swap(grid[now][i],grid[now-1][i]);
                    now--;
                }
            }
        }
        return grid;
    }
};