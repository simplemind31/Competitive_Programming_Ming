#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
class Solution{
public:
    int n,m,si,sj,con;
    int minMoves(vector<string>& grid, int energy){
        n=grid.size();
        m=grid[0].size();
        for(int i=con=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='S')si=i,sj=j;
                else if(grid[i][j]=='L')grid[i][j]=con++;
            }
        }
        int dp[n][m][energy+1][1<<con];
        fill(&dp[0][0][0][0],&dp[0][0][0][0]+n*m*(energy+1)*(1<<con),1e9);
        dp[si][sj][energy][0]=0;
        queue<pair<pair<int,int>,pair<int,int>>> bfs;
        bfs.push({{si,sj},{energy,0}});
        while(!bfs.empty()){
            pair<pair<int,int>,pair<int,int>> top=bfs.front();
            int a=top.first.first,b=top.first.second,c=top.second.first,d=top.second.second;
            bfs.pop();
            if(grid[a][b]=='X')continue;
            if(grid[a][b]<10){
                dp[a][b][c][d|(1<<grid[a][b])]=dp[a][b][c][d];
                d|=1<<grid[a][b];
            }else if(grid[a][b]=='R'){
                dp[a][b][energy][d]=dp[a][b][c][d];
                c=energy;
            }
            if(d==(1<<con)-1)return dp[a][b][c][d];
            if(c==0)continue;
            if(a-1>=0 && dp[a-1][b][c-1][d]==1e9){
                dp[a-1][b][c-1][d]=dp[a][b][c][d]+1;
                bfs.push({{a-1,b},{c-1,d}});
            }
            if(a+1<n && dp[a+1][b][c-1][d]==1e9){
                dp[a+1][b][c-1][d]=dp[a][b][c][d]+1;
                bfs.push({{a+1,b},{c-1,d}});
            }
            if(b-1>=0 && dp[a][b-1][c-1][d]==1e9){
                dp[a][b-1][c-1][d]=dp[a][b][c][d]+1;
                bfs.push({{a,b-1},{c-1,d}});
            }
            if(b+1<m && dp[a][b+1][c-1][d]==1e9){
                dp[a][b+1][c-1][d]=dp[a][b][c][d]+1;
                bfs.push({{a,b+1},{c-1,d}});
            }
        }
        return -1;
    }
};